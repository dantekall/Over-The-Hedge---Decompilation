# OTHDecomp Makefile scaffold

CROSS_COMPILE ?= mips-linux-gnu-
CC            := $(CROSS_COMPILE)gcc
LD            := $(CROSS_COMPILE)ld
CFLAGS        := -O2 -G0 -mabi=eabi -mcpu=r5900 -Iinclude
LDFLAGS := -T config/linker.ld -nostdlib -Wl,-Map=build/OTH.map

SRC_FILES     := $(wildcard src/*.c)
OBJ_FILES     := $(SRC_FILES:src/%.c=build/%.o)

all: build/OTH.elf

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
