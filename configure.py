#!/usr/bin/env python3
import argparse
import os
import sys
from pathlib import Path
import shutil

try:
    import splat
    import splat.scripts.split as split
except ImportError:
    print("Error: 'splat' package not found.")
    print("Please install dependencies first by running: pip install -r requirements.txt")
    sys.exit(1)

ROOT_DIR = Path(__file__).parent.resolve()
CONFIG_PATH = ROOT_DIR / "splat.yaml"

def main():
    parser = argparse.ArgumentParser(description="Configure Over The Hedge decompilation build system.")
    parser.add_argument("--clean", action="store_true", help="Clean build directory before configuring")
    parser.add_argument("--skip-checksum", action="store_true", help="Skip matching checksum verification")
    parser.add_argument("--objdiff", action="store_true", help="Generate objdiff configuration")
    args = parser.parse_args()

    build_dir = ROOT_DIR / "build"
    if args.clean and build_dir.exists():
        print("Cleaning existing build directory...")
        shutil.rmtree(build_dir)

    build_dir.mkdir(exist_ok=True)

    if not CONFIG_PATH.exists():
        print(f"Error: Splat configuration file not found at {CONFIG_PATH}")
        sys.exit(1)

    print(f"Running Splat split using config: {CONFIG_PATH.name}")
    # Invoke Splat's split engine to slice the ELF and generate build rules
    split.main([str(CONFIG_PATH), "--target", "all"])

    print("\nConfiguration complete! You are ready to execute: ninja")

if __name__ == "__main__":
    main()
