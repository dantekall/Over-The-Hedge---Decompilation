# File: src/entry.s
# Clean startup routine for Over The Hedge (SLUS_213.00)

    .set noreorder
    .global _start
    .ent _start
    .extern _gp

_start:
    # 1. Initialize Global Pointer
    la      $gp, _gp

    # 2. Initialize Stack Pointer ($sp) to a safe location in high EE RAM (0x01FFF000)
    lui     $sp, 0x01ff
    ori     $sp, $sp, 0xff00

    # 3. Zero out the BSS section
    la      $t0, __bss_start
    la      $t1, _end
_clear_bss:
    slt     $at, $t0, $t1
    beq     $at, $zero, _call_main
    nop
    sw      $zero, 0x0($t0)
    b       _clear_bss
    addiu   $t0, $t0, 4

_call_main:
    # 4. Call main(0, 0)
    move    $a0, $zero
    move    $a1, $zero
    jal     main
    nop

_hang:
    # 5. If main ever returns, trap the CPU in an infinite loop
    b       _hang
    nop

.end _start
