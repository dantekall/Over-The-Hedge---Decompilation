# Over The Hedge (PS2) Decompilation Makefile

BUILD_DIR = build
TARGET = $(BUILD_DIR)/SLUS_213.00

# Docker container wrapper
DOCKER_RUN = docker run --rm -v $(shell pwd):/src -w /src ps2dev/ps2dev
CXX = mips64r5900el-ps2-elf-g++

# Compiler flags
CFLAGS = -O2 -G0 -xc++ -g2 -march=r5900 -mabi=eabi -mno-abicalls -fno-rtti -fno-exceptions -Iinclude

# Object files list (using entry.o for authentic assembly bootstrap)
OBJS = $(BUILD_DIR)/entry.o $(BUILD_DIR)/main.o $(BUILD_DIR)/FOO.o $(BUILD_DIR)/resource_loader.o $(BUILD_DIR)/stubs.o

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Linker rule
$(TARGET): $(OBJS)
	@echo "Linking $(TARGET)..."
	$(DOCKER_RUN) $(CXX) $(OBJS) -march=r5900 -mabi=eabi -mno-abicalls -nostdlib -Wl,-m,elf32lr5900 -T ps2.ld -o $(TARGET) -Wl,-Map=$(BUILD_DIR)/SLUS_213.map
	@echo "Build complete: $(TARGET)"

# Assembly rule for the retail entry point (compiled as pure assembly, no -xc++)
$(BUILD_DIR)/entry.o: src/entry.s
	$(DOCKER_RUN) mips64r5900el-ps2-elf-gcc -march=r5900 -mabi=eabi -mno-abicalls -c $< -o $@

# C++ compilation rules
$(BUILD_DIR)/main.o: src/main.cpp
	$(DOCKER_RUN) $(CXX) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/FOO.o: src/classes/FOO.cpp
	$(DOCKER_RUN) $(CXX) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/resource_loader.o: src/engine/resource_loader.cpp
	$(DOCKER_RUN) $(CXX) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/stubs.o: src/stubs.cpp
	$(DOCKER_RUN) $(CXX) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all clean
