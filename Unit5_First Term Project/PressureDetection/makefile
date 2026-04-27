CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m3 -gdwarf-2 -g
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
Project_name = PressureSystem
Linker_Script = linkerscript
all: $(Project_name).hex
	@echo "=======================Compiling Done============================="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) $(LIBS) -c -std=c99 $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T $(Linker_Script).ld -Map=Map_file.map $(LIBS) $(OBJ) $(AsOBJ) -o $@

$(Project_name).hex: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@


clear:
	rm *.o *.elf *.hex
	@echo "=======================Cleaning Done=============================="
