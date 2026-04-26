CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m3 -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o)
all: learn-in-depth_cortexM4.hex
	@echo "=======================Compiling Done============================="

%.o: %.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) $(LIBS) -c -std=c99 $< -o $@

learn-in-depth.elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld -Map=Map_file.map $(LIBS) $(OBJ) $(AsOBJ) -o $@

learn-in-depth_cortexM4.hex: learn-in-depth.elf
	$(CC)objcopy.exe -O binary $< $@


clear:
	rm *.o *.elf *.hex
	@echo "=======================Cleaning Done=============================="
