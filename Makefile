CC = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0
LDFLAGS =  -nostdlib -T linker_stm32fxx.ld -Wl,-Map=final.map

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
DUMP = $(patsubst src/%.c, debug/%.s, $(SRC))

program: $(OBJ) obj/stm32f4xx_startup.o final.elf
	@echo "finalizado."

debug: $(DUMP)
	@echo "finalizado."

debug/%.s: obj/%.o | dump
	$(OBJDUMP) -D $< > $@

obj/%.o: src/%.c | obj
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -Iinc -o $@ $<

obj/stm32f4xx_startup.o: startup/stm32f4xx_startup.c 
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -Iinc -o $@ $<

final.elf:
	$(CC) $(LDFLAGS) -o $@ obj/*.o

obj:
	mkdir -p obj

dump:
	mkdir -p debug

clean:
	rm -rf obj debug *.o *.s *.elf *.map
