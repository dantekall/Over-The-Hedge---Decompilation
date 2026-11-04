import sys
import yaml

def validate_splat(yaml_path):
    print(f"[+] Validating Splat configuration: {yaml_path}")
    try:
        with open(yaml_path, 'r') as f:
            config = yaml.safe_load(f)
    except Exception as e:
        print(f"::error file={yaml_path},line=1::Failed to parse YAML: {e}")
        sys.exit(1)

    segments = config.get('segments', [])
    last_end = 0
    errors = 0

    for i, seg in enumerate(segments):
        if isinstance(seg, dict):
            start = seg.get('start', None)
            name = seg.get('name', f'segment_{i}')
            if start is not None:
                if start < last_end:
                    print(f"::error file={yaml_path}::Overlap detected in segment '{name}': start address 0x{start:X} is less than previous end 0x{last_end:X}")
                    errors += 1
                end = seg.get('end', start)
                last_end = end

    if errors == 0:
        print("[+] Splat configuration validated successfully! No boundary overlaps detected.")
        sys.exit(0)
    else:
        print(f"[!] Found {errors} validation error(s).")
        sys.exit(1)

if __name__ == "__main__":
    target = sys.argv[1] if len(sys.argv) > 1 else "splat.yaml"
    validate_splat(target)
