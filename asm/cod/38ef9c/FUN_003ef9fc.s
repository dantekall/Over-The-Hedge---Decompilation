.global _start
_start:
    .set noreorder

    or      $t0, $a0, $a1
    andi    $v0, $t0, 0x7
    bnel    $v0, $zero, LAB_003efb34
    andi    $t1, $t0, 0xf

    ori     $a3, $a3, 0x101
    ori     $a2, $a2, 0x8080
    bne     $t1, $zero, LAB_003efac8
    lq      $v1, 0x0($a0)

    pcpyld  $t0, $a3, $a3
    lq      $v0, 0x0($a1)
    pcpyld  $t2, $a2, $a2
    psubw   $a3, $v0, $v1
    pcpyud  $a2, $a3, $a0
    or      $v1, $a2, $a3
    bnel    $v1, $zero, LAB_003efb34
    lq      $v0, 0x0($a0)

    pnor    $v1, $zero, $v0

LAB_003efa7c:
    psubb   $v0, $v0, $t0
    pand    $v0, $v0, $v1
    pand    $v0, $v0, $t2
    pcpyud  $v1, $v0, $a0
    or      $a2, $v1, $v0
    beq     $a2, $zero, LAB_003efaa0
    jr      $ra
    nop

LAB_003efaa0:
    addiu   $a1, $a1, 0x10
    lq      $v0, 0x0($a0)
    lq      $v1, 0x0($a1)
    psubw   $a3, $v0, $v1
    pcpyud  $a2, $a3, $a0
    or      $t1, $a2, $a3
    beql    $t1, $zero, LAB_003efa7c
    nop
    b       LAB_003efb34
    nop

LAB_003efac8:
    ld      $v1, 0x0($a0)
    bnel    $v1, $v0, LAB_003efb34
    ld      $v0, 0x0($a0)

    nor     $t0, $zero, $v0

LAB_003efadc:
    dsubu   $v0, $v0, $a3
    and     $v0, $v0, $t0
    and     $v0, $v0, $a2
    beq     $v0, $zero, LAB_003efaf8
    jr      $ra
    nop

LAB_003efaf8:
    addiu   $a1, $a1, 0x8
    ld      $v0, 0x0($a0)
    ld      $v1, 0x0($a1)
    beql    $v1, $v0, LAB_003efadc
    nop
    b       LAB_003efb34
    nop

LAB_003efb14:
    lb      $v1, 0x0($a1)
    sra     $v0, $v0, 0x18
    bnel    $v0, $v1, LAB_003efb3c
    addiu   $a0, $a0, 0x1
    addiu   $a1, $a1, 0x1
    lb      $v0, 0x0($a0)

LAB_003efb34:
    bne     $v0, $zero, LAB_003efb14
    nop

LAB_003efb3c:
    lbu     $v0, 0x0($a1)
    jr      $ra
    nop
