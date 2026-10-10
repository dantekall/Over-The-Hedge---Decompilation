path = 'asm/entry.s'
try:
    with open(path, 'r') as f:
        lines = f.readlines()

    filtered_lines = []
    for line in lines:
        stripped = line.strip()
        if stripped.startswith('.set mips') or stripped.startswith('.set r5900'):
            continue
        filtered_lines.append(line)

    content = ''.join(filtered_lines)
    directives = '.set noreorder\n.set noat\n'

    if not content.startswith('.set noreorder'):
        content = directives + content

    with open(path, 'w') as f:
        f.write(content)
    print("Successfully cleaned and patched asm/entry.s.")
except FileNotFoundError:
    print(f"Warning: {path} not found.")
