CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
ProjectName = LedBlink
all: $(ProjectName).bin
	@echo "=======================Compiling Done============================="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe -std=c99 -c $(CFLAGS) $(INCS) $< -o $@

$(ProjectName).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=Map_file.map $(LIBS) $(OBJ) $(AsOBJ) -o $@

$(ProjectName).bin: $(ProjectName).elf
	$(CC)objcopy.exe -O binary $< $@

clear:
	rm *.o *.elf *.hex
	@echo "=======================Cleaning Done=============================="
