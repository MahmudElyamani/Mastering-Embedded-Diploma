#include <Arduino.h>

/*
  100 Hz PWM on pin D3 (Arduino Nano), duty cycle set by a potentiometer on A0
  Button on pin D2 (external pull-down, rising edge) toggles the whole circuit ON/OFF:
    - ON  -> PWM runs on pin 3, LEDs on pins 8, 9, 10 are lit
    - OFF -> pin 3 forced LOW, LEDs off
  --------------------------------------------------------------------------
  Why not analogWrite() for the PWM?
  Pin 3 is driven by Timer2 on the ATmega328. Timer2 is only 8-bit, so with the
  prescalers it supports you cannot land exactly on 100 Hz (you get ~488 Hz,
  ~244 Hz, ~61 Hz, etc., but never exactly 100 Hz).

  Solution used here:
  Timer1 (16-bit) runs in CTC mode purely as a precise time base, and pin D3
  is toggled manually from two compare-match interrupts:
    - OCR1A defines the period (100 Hz exactly)
    - OCR1B defines when, inside that period, the pin goes LOW (this sets duty)

  Timer1 clock = 16 MHz / 8 (prescaler) = 2 MHz
  Period for 100 Hz = 2,000,000 / 100 = 20,000 counts -> TOP (OCR1A) = 19999
*/

const uint8_t pwmPin   = 3;      // D3 = PD3
const uint8_t potPin   = A0;
const uint8_t buttonPin = 2;     // D2, supports hardware interrupt (INT0)
const uint8_t ledPins[3] = {8, 9, 10};

const uint16_t topValue = 19999;      // sets 100 Hz exactly (see header comment)
volatile uint16_t compareValue = 0;   // OCR1B shadow, used for duty calc in ISR

volatile bool systemOn = false;       // circuit starts OFF
volatile unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 200; // ms, minimum time between toggles

void buttonISR();
void updateLEDs();

void setup() {
  pinMode(pwmPin, OUTPUT);
  digitalWrite(pwmPin, LOW);

  for (uint8_t i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(buttonPin, INPUT); // external pull-down resistor handles the idle state
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonISR, RISING);

  Serial.begin(9600);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  TCCR1B |= (1 << WGM12);   // CTC mode, TOP = OCR1A
  TCCR1B |= (1 << CS11);    // prescaler = 8

  OCR1A = topValue;         // period -> 100 Hz
  OCR1B = 0;                // start at 0% duty

  TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B); // enable both compare interrupts
  interrupts();
}

void loop() {
  int potValue = analogRead(potPin);   // 0..1023

  // Map to 0..(topValue-1) so 100% duty (pin always high) is never confused
  // with the simultaneous COMPA/COMPB match that would occur at compare==top.
  uint16_t newCompare = map(potValue, 0, 1023, 0, topValue - 1);

  noInterrupts();
  compareValue = newCompare;
  OCR1B = compareValue;
  interrupts();

  float dutyPercent = (compareValue / (float)(topValue - 1)) * 100.0;

  Serial.print("System: ");
  Serial.print(systemOn ? "ON " : "OFF");
  Serial.print("\tA0: ");
  Serial.print(potValue);
  Serial.print("\tDuty Cycle: ");
  Serial.print(dutyPercent, 1);
  Serial.println(" %");

  delay(200);
  
}

// Toggles systemOn state, debounced, and updates LEDs immediately
void buttonISR() {
  unsigned long now = millis();
  if (now - lastDebounceTime > debounceDelay) {
    systemOn = !systemOn;
    lastDebounceTime = now;
    updateLEDs();
    if (!systemOn) {
      PORTD &= ~(1 << PD3); // force PWM pin low immediately when turning off
    }
  }
}

void updateLEDs() {
  for (uint8_t i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], systemOn ? HIGH : LOW);
  }
}

// Fires at the end of each 100 Hz period -> start of new cycle -> pin HIGH
ISR(TIMER1_COMPA_vect) {
  if (systemOn && compareValue > 0) {
    PORTD |= (1 << PD3);   // set pin 3 high
  }
  // if system is off or compareValue == 0, leave pin low
}

// Fires when the counter reaches the duty threshold -> pin LOW
ISR(TIMER1_COMPB_vect) {
  PORTD &= ~(1 << PD3);    // set pin 3 low
}