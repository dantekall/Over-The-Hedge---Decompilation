# File: src/entry.s
# Entry point / Low-level runtime initialization for Over The Hedge (SLUS_213.00)

    .set noreorder
    .global _start
    .ent _start
    .extern _gp

_start:
    # 1. Initialize Global Pointer
    la      $gp, _gp

    # Initialize pointers for data/BSS clearing
    la      $v0, __bss_start
    la      $v1, _end

    sw      $zero, 0x0($v0)
    sync.l
    addiu   $v0, $v0, -0x5100

LAB_00100138:
    andi    $a0, $v0, 0xf
    beq     $a0, $zero, LAB_00100158
    nop
    sb      $zero, 0x0($v0)
    addiu   $v0, $v0, 0x1

LAB_00100158:
    b       LAB_00100164
    nop

LAB_00100164:
    beq     $v0, $a0, LAB_00100184
    nop
    sq      $zero, 0x0($v0)             # Quadword zero store (PS2 Emotion Engine specific)
    addiu   $v0, $v0, 0x10

LAB_00100184:
    beq     $v0, $v1, LAB_001001a4
    nop
    sb      $zero, 0x0($v0)
    addiu   $v0, $v0, 0x1

LAB_001001a4:
    # System calls and initialization jumps
    syscall 0x0
    syscall 0x0
    jal     FUN_003d9100                # Initialize game subsystems
    nop
    jal     FlushCache                  # Flush instruction/data caches
    nop
    jal     FUN_0027cb00                # Post-subsystem setup
    nop
    ei                                  # Enable interrupts

    beq     $v1, $zero, LAB_00100230
    nop
    addiu   $v0, $v1, 0x4
    addiu   $v0, $v0, -0x3740

LAB_00100230:
    nop

LAB_00100238:
    lw      $a0, 0x0($v0)
    jal     FUN_0027ca68                # Initialize scene
    nop
    j       FUN_00100258                # Jump to worker thread entry
    nop

.end _start
