# Simple Makefile for Over The Hedge Decompilation
PYTHON = python3
SPLAT = $(PYTHON) -m splat.split
BUILD_DIR = build
ROM = SLUS_213.00

all: $(BUILD_DIR)/$(ROM)

$(BUILD_DIR)/$(ROM): splat.yaml Decompilation/Engine/ResourceLoader.c
	@echo "Running Splat splitter..."
	$(SPLAT) splat.yaml
	@echo "Compiling source files..."
	ee-gcc -O2 -c src/ResourceLoader.c -o $(BUILD_DIR)/Decompilation/Engine/ResourceLoader.o
	@echo "Linking binary..."
	# Linker command to produce matching output...
	@echo "Build complete!"

clean:
	rm -rf $(BUILD_DIR)
