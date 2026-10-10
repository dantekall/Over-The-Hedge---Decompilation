# Toolchain definition for PlayStation 2 EE (Emotion Engine)
CROSS_COMPILE ?= mips64r5900el-ps2-elf-
CC            := $(CROSS_COMPILE)gcc
CXX           := $(CROSS_COMPILE)g++
LD            := $(CROSS_COMPILE)ld
OBJCOPY       := $(CROSS_COMPILE)objcopy

# Docker wrapper for ps2dev environment
DOCKER_RUN    := docker run --rm -v "$(PWD)":/workspace -w /workspace ps2dev/ps2dev

# Compiler flags targeting PS2 GCC specs
CFLAGS    := -O2 -G0 -mabi=eabi -mips3 -mcpu=r5900 -Iinclude
CXXFLAGS := $(CFLAGS) -fno-exceptions -fno-rtti

# Targets
BUILD_DIR := build
OUT_DIR   := out
TARGET    := $(OUT_DIR)/SLUS_213.00

.PHONY: all clean split

all: $(TARGET)

# Step A: Run Splat to split the binary and generate linker script (runs locally)
split:
	python3 -m splat split config/splat.yaml

# Step B: Compile C++ files inside Docker
$(BUILD_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(DOCKER_RUN) $(CXX) $(CXXFLAGS) -c $< -o $@

# Step C: Assemble ASM files inside Docker
$(BUILD_DIR)/%.o: asm/%.s
	@mkdir -p $(dir $@)
	$(DOCKER_RUN) $(CC) $(CFLAGS) -c $< -o $@

# Step D: Link object files inside Docker using Splat's linker script
$(TARGET): split
	@mkdir -p $(OUT_DIR)
	$(DOCKER_RUN) $(LD) -T build/link.ld -o $@
	@echo "Build complete: $(TARGET)"

clean:
	rm -rf $(BUILD_DIR) $(OUT_DIR) asm/
