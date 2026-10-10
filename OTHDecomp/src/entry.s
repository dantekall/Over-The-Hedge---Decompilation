.set noreorder
.set noat
.set noreorder
.set noat
.set push
.set noreorder
.set noat

.global __start
__start:
    sw      $zero, 0x0($v0)
    sync
    addiu   $v0, $v0, -0x5100

LAB_00100138:
    andi    $a0, $v0, 0xf
    beq     $a0, $zero, LAB_00100158
    sb      $zero, 0x0($v0)
    addiu   $v0, $v0, 0x1

LAB_00100164:
    beq     $v0, $a0, LAB_00100184
    sq      $zero, 0x0($v0)         # 128-bit Quadword store
    addiu   $v0, $v0, 0x10

LAB_00100184:
    beq     $v0, $v1, LAB_001001A4  # Note: ensure label case matches definition
    sb      $zero, 0x0($v0)
    addiu   $v0, $v0, 0x1

    syscall 0x0
    syscall 0x0
    jal     InitalizeRuntime
    jal     FlushCache
    jal     InitalizeSubSystems
    ei

    beq     $v1, $zero, LAB_00100230
    addiu   $v0, $v1, 0x4
    addiu   $v0, $v0, -0x3740

LAB_00100238:
    lw      $a0, 0x0($v0)
    jal     InitalizeGameRuntime
    j       InitalizeGameState

.set pop
