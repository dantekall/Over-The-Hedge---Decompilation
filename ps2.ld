OUTPUT_FORMAT("elf32-littlemips")
OUTPUT_ARCH(mips)
ENTRY(_start)

SECTIONS
{
    /* Over The Hedge base memory address */
    . = 0x00100000;

    .text : {
        build/entry.o(.text)
        *(.text)
        *(.text.*)
    }

    .rodata : {
        *(.rodata)
        *(.rodata.*)
    }

    .data : {
        *(.data)
        *(.data.*)
    }

    /* Global pointer setup for MIPS */
    . = ALIGN(16);
    _gp = . + 0x7ff0;

    .lit8 : { *(.lit8) }
    .lit4 : { *(.lit4) }

    /* BSS section with explicit start and end symbols */
    . = ALIGN(16);
    __bss_start = .;
    .bss : {
        *(.bss)
        *(COMMON)
    }
    . = ALIGN(16);
    _end = .;
}
