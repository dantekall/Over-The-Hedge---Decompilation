import subprocess
import sys
import os

def run_build():
    print("[OTHDecomp] Running build...")
    result = subprocess.run(["make"], capture_output=True, text=True)
    print(result.stdout)
    if result.returncode != 0:
        print(result.stderr, file=sys.stderr)
        print("[OTHDecomp] Build failed.")
        sys.exit(1)
    else:
        print("[OTHDecomp] Build successful!")

if __name__ == "__main__":
    run_build()
