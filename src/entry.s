.set noreorder
.set noat

.globl _start
_start:
    # Entry initialization routines
    sw      zero, 0x0($v0)         # DAT_00412e98
    sync.l  0x10
    addiu   v0, v0, -0x5100

.L_entry_loop:
    andi    a0, v0, 0xf
    beq     a0, zero, .L_target_1
    sb      zero, 0x0(v0)          # Delay slot: clear byte
    
    addiu   v0, v0, 0x1

.L_target_1:
    beq     v0, a0, .L_target_2
    sq      zero, 0x0(v0)          # Delay slot: quadword clear
    
    addiu   v0, v0, 0x10

.L_target_2:
    beq     v0, v1, .L_target_3
    sb      zero, 0x0(v0)          # Delay slot
    
    addiu   v0, v0, 0x1

    # System calls and core initialization jumps
    syscall 0x0
    syscall 0x0
    jal     FUN_003d9100
    jal     FlushCache
    jal     FUN_0027cb00
    ei
    beq     v1, zero, .L_target_4
    addiu   v0, v1, 0x4

    addiu   v0, v0, -0x3740

.L_target_3:
    lw      a0, 0x0(v0)
    jal     FUN_0027ca68
    j       FUN_00100258

.L_target_4:
    # End of startup sequence placeholder
    jr      ra
    nop
