OUTPUT_FORMAT("elf32-littlemips")
OUTPUT_ARCH(mips)
ENTRY(_start)

MEMORY
{
    /* PS2 Emotion Engine main RAM layout (typical user memory starting at 0x00100000) */
    ram (rwx) : ORIGIN = 0x00100000, LENGTH = 32M
}

SECTIONS
{
    . = 0x00100000;

    .text : {
        *(.text)
        *(.text.*)
    } > ram

    .rodata : {
        *(.rodata)
        *(.rodata.*)
    } > ram

    .data : {
        *(.data)
        *(.data.*)
    } > ram

    .bss : {
        _bss_start = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        _bss_end = .;
    } > ram
}
