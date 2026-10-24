# File: asm/cod/000000/entry.s
# Entry point / Low-level runtime initialization

    .set noreorder

    # Initialize data/BSS sections and hardware registers
    sw      zero, 0x0(v0)           # Store zero at DAT_00412e98
    sync.l  0x10                    # Memory synchronization barrier
    addiu   v0, v0, -0x5100

LAB_00100138:
    andi    a0, v0, 0xf
    beq     a0, zero, LAB_00100158
    sb      zero, 0x0(v0)           # Zero out byte at DAT_0048af00
    addiu   v0, v0, 0x1

LAB_00100164:
    beq     v0, a0, LAB_00100184
    sq      zero, 0x0(v0)           # Quadword zero store (PS2 Emotion Engine specific!)
    addiu   v0, v0, 0x10

LAB_00100184:
    beq     v0, v1, LAB_001001a4
    sb      zero, 0x0(v0)           # Zero out byte at DAT_0048af10
    addiu   v0, v0, 0x1

    # System calls and initialization jumps
    syscall 0x0
    syscall 0x0
    jal     FUN_003d9100            # Initialize game subsystems
    nop
    jal     FlushCache              # Flush instruction/data caches
    nop
    jal     FUN_0027cb00            # Post-subsystem setup
    nop
    ei                              # Enable interrupts

    beq     v1, zero, LAB_00100230
    addiu   v0, v1, 0x4
    addiu   v0, v0, -0x3740

LAB_00100238:
    lw      a0, 0x0(v0)             # Load reference from DAT_0048c8c0
    jal     FUN_0027ca68            # Initialize scene
    nop
    j       FUN_00100258            # Jump to worker thread entry
    nop
