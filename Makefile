CC = arm-none-eabi-gcc
MACH = cortex-m4
CFLAGS = -c -mcpu=$(MACH) -mthumb -std=gnu11 -O0

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

program: $(OBJ)
	@echo "finalizado."

obj/%.o: src/%.c | obj
	@echo "Compilando $<..."
	@$(CC) $(CFLAGS) -Iinc -o $@ $<

obj:
	mkdir obj
