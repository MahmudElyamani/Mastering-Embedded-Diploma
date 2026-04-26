#@copyright: Mahmood Elyamani

CC=arm-none-eabi-
CFLAG=-g -mcpu=arm926ej-s
INCS=-I .
LIB=
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
As=$(wildcard *.s)
AsOBJ=$(As:.s=.o)
all: learn-in-depth.bin
	@echo "=========Build is done==========="


%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@


%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@


learn-in-depth.elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(OBJ) $(AsOBJ) -o $@



learn-in-depth.bin: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@



clear:
	rm *.o *.elf *.bin
