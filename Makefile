# Over The Hedge (PS2) Decompilation Makefile

BUILD_DIR = build
TARGET = $(BUILD_DIR)/SLUS_213.00

# Compiler & Toolchain settings (using Docker container)
DOCKER_CMD = docker run --rm -v $(shell pwd):/workspace mipsr5900ps2elfgcc
CXX = mips64r5900el-ps2-elf-g++
AS = mips64r5900el-ps2-elf-as
LD = mips64r5900el-ps2-elf-ld

# Compiler flags
CFLAGS = -O2 -G0 -xc++ -fopt-stack -g2 -mabi=eabi -mcpu=r5900 -Iinclude

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Split ROM using Splat (if config exists)
split:
	python3 tools/splat/split.py splat.yaml

# Build target executable
$(TARGET): src/main.cpp
	@echo "Building project..."
	# Add your compilation & linking rules here
	touch $(TARGET)
	@echo "Build complete: $(TARGET)"

clean:
	rm -rf $(BUILD_DIR)/*.elf $(BUILD_DIR)/SLUS_213.00

.PHONY: all split clean
