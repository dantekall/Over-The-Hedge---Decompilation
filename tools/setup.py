#!/usr/bin/env python3
import os
from pathlib import Path

ROOT_DIR = Path(__file__).parent.parent.resolve()
ISO_DIR = ROOT_DIR / "iso"

REQUIRED_FILES = [
    "SLUS_213.00",
    "EORPS2IO.IRX",
    "LIBSD.IRX",
    "MCMAN.IRX",
    "MCSERV.IRX",
    "PADMAN.IRX",
    "SDRDRV.IRX",
    "SIO2MAN.IRX"
]

def main():
    print("--- Over The Hedge Workspace Setup ---")

    if not ISO_DIR.exists():
        print(f"Creating missing 'iso/' folder at: {ISO_DIR}")
        ISO_DIR.mkdir(exist_ok=True)
        print("Please place your extracted ISO files inside the 'iso/' directory.")

    # Verify required assets
    missing_files = []
    for filename in REQUIRED_FILES:
        found = False
        for p in ISO_DIR.rglob("*"):
            if p.name.upper() == filename.upper():
                found = True
                break
        if not found:
            missing_files.append(filename)

    if missing_files:
        print("\n[NOTICE] The following expected files were not found in your 'iso/' directory yet:")
        for m in missing_files:
            print(f"  - {m}")
        print("Make sure to extract them from your retail disc before running the build.")
    else:
        print("\nAll core executable and driver assets verified successfully!")

    # Ensure required working directories exist
    folders = ["src", "include", "asm", "config", "progress", "expected"]
    for folder in folders:
        p = ROOT_DIR / folder
        p.mkdir(exist_ok=True)
        print(f"Verified directory structure: {folder}/")

    print("\nSetup utility completed successfully. Run 'python3 configure.py' next!")

if __name__ == "__main__":
    main()

if __name__ == "__main__":
    main()
