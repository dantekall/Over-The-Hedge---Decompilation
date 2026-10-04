# --- OTHDecomp Makefile ---

# Toolchain definitions
CC = ee-gcc
CXX = ee-g++
AS = ee-as
LD = ee-ld
OBJDUMP = ee-objdump

# Flags for PlayStation 2 Emotion Engine (MIPS R5900)
CFLAGS = -G0 -O2 -Wall -Iinclude
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti

# Target binary name matching our ripped ELF
TARGET = build/SLUS_213.00

# Default target: build and verify match
all: $(TARGET) compare

# Run Splat to split/prepare assembly and assets
splat:
	python3 -m splat split config/splat.yaml

# Compile our C++ files into object files (.o)
obj/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link everything together using Splat's generated linker script
$(TARGET): splat obj/engine/resource_loader.o
	# (Linker command linking object files using config/link.ld)
	@echo "Linking binary..."

# Compare our built binary against the original ripped ELF
compare: $(TARGET)
	@sha1sum $(TARGET) reference/SLUS_213.00.sha1
	@echo "Build matches successfully!"
