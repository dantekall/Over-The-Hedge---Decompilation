OTHDecomp aims to write code that compiles into a 100% identical copy of the game's executable. Once all of the code of the game is in source form, we can make our own changes to the game, or port it to other platforms such as PC or the Nintendo Switch.

This process requires that you own a copy of the game already. None of the original game assets or proprietary source files are committed to this repository.


To dive right in, use the setup guide and find an assembly function in the asm folder. You need to find a function that is mall and good for a first attempt. Here's an example of what we're looking for below.

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

Visit the website decomp.me and create a new scratch there. Paste in the assembly and select EE GCC 2.95.3 (SN 1.73)

Now this is the work of decompilation. Try to edit the source file and its context until the assembly matches. On decomp.me, the m2c decompiler will give a decent starting point, and the goal is to fix all of the errors and mismatches until it is a 100% match. 




If you've completed the quickstart above, thank you so much!

Submitting changes to the repository looks like so:

    Locate the C file where the code belongs. For example, the above function lives in src/engine/Resource_loader.c. If a C file doesn't exist, you may have to update the Splat YAML file to change asm -> c and rodata -> .rodata (see the Splat docs for more information).
    Find the INCLUDE_ASM line where the function is referenced and replace it with the decompiled code.
    Update or create any other files as needed, including header files.
    Run make clean. 
    Run make clean, then make to make sure the build is passing.

Once that's done, feel free to submit a pull request! Please try your best to submit changes that keep the build matching, but if you run into issues you may make a PR anyway so we can help troubleshoot.















We need to extract assembly from the file we want to decompile. For this we use a disassembler, this project uses spimdisasm via splat.

Splat allows us to describe the structure of our file using a markdown format. For example, see the OTHDecomp project YAML at SLUS_213.00.yaml. 
step 2: assembly files → binary (again)

After disassembling everything, we need to assemble the resulting assembly (.s) files into individual object (.o) files. These object files should be able to be stitched back together into something that matches the file we started with.

For this we use the GNU assembler, as, from binutils. This project uses a fork of as found at binutils-mips-ps2-decompals.

Note that no code is involved yet, we haven't compiled any C files.
step 3: .o files → executable file

After successfully splitting the binary apart and assembling each piece, the linker stitches all the object files back together to create the Over The Hedge eexecutable.

The linker this project uses is ps2.ld, and it was compiled wiht ProDG.

If the linker plays nice, then we end up with a file that 100% matches the one we started with.
step 4: assembly files → code

Now that we've done this whole dance of diassembling, assembling, and linking, the decompilation work begins.

A project can often be started by taking just one function out of the binary. In Splat, we find an assembly split:

    - [0x000000, asm, code]

and change it to a code split for C (or C++ in other projects):

    - [0x000000, asm, code_0]
    - [0x000040, c,   resource_loader]
    - [0x000080, asm, code_1]

This tells Splat that this split is now implemented in C, so it will be compiled with PS2DEV instead of assembled from plain assembly.

Now the goal is to write C code that matches (see quickstart). The function is considered matched when we can compile C code into an object (.o) file identical the one we would get via assembling the function's assembly.

Since this new .o file from the C compiler should be interchangeable with the .o file from the assembler, we can use it when linking. If all works out, we have an identical copy of Over The edge!
summary

This is a general overview of how the "Ship of Theseus" approach to decompilation works. We split a game into binary files, and replace those binary files one-by-one with compiled C code. This guide leaves out a lot of detail and nuance about topics such as ELF sections (data, rodata, bss, sdata, etc.), symbols, linker scripts, compiler optimizations, etc., but hopefully it should clear up what the project is about and how it works. It can likely be improved, please feel free to leave an issue if you have suggestions.
