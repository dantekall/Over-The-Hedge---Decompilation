SECTIONS
{
    HIDDEN(__romPos = 0);
    _gp = cod_SDATA_START + 0x7FF0;
    cod_ROM_START = __romPos;
    cod_VRAM = ADDR(.cod);
    .cod 0x100000 : AT(cod_ROM_START)
    {
        FILL(0x00000000);
        cod_TEXT_START = .;
        build/src/main.o(.text*);
        build/src/engine/resource_loader.o(.text*);
        build/src/actors/FOO.o(.text*);
        build/src/game/CharacterManager.o(.text*);
        build/asm/entry.o(.text*);
        build/asm/data/cod/30A130.o(.text*);
        . = ALIGN(., 16);
        cod_TEXT_END = .;
        cod_TEXT_SIZE = ABSOLUTE(cod_TEXT_END - cod_TEXT_START);
        cod_DATA_START = .;
        build/src/main.o(.data*);
        build/src/engine/resource_loader.o(.data*);
        build/src/actors/FOO.o(.data*);
        build/src/game/CharacterManager.o(.data*);
        build/asm/entry.o(.data*);
        build/asm/data/cod/30A130.o(.data*);
        build/asm/data/cod/312800.data.o(.data*);
        . = ALIGN(., 16);
        cod_DATA_END = .;
        cod_DATA_SIZE = ABSOLUTE(cod_DATA_END - cod_DATA_START);
        cod_RODATA_START = .;
        build/src/main.o(.rodata*);
        build/src/engine/resource_loader.o(.rodata*);
        build/src/actors/FOO.o(.rodata*);
        build/src/game/CharacterManager.o(.rodata*);
        build/asm/entry.o(.rodata*);
        build/asm/data/cod/30A130.o(.rodata*);
        build/asm/data/cod/321200.rodata.o(.rodata*);
        . = ALIGN(., 16);
        cod_RODATA_END = .;
        cod_RODATA_SIZE = ABSOLUTE(cod_RODATA_END - cod_RODATA_START);
        cod_GCC_EXCEPT_TABLE_START = .;
        build/src/main.o(.gcc_except_table*);
        build/src/engine/resource_loader.o(.gcc_except_table*);
        build/src/actors/FOO.o(.gcc_except_table*);
        build/src/game/CharacterManager.o(.gcc_except_table*);
        build/asm/entry.o(.gcc_except_table*);
        build/asm/data/cod/30A130.o(.gcc_except_table*);
        build/asm/data/cod/38A680.gcc_except_table.o(.gcc_except_table*);
        . = ALIGN(., 16);
        cod_GCC_EXCEPT_TABLE_END = .;
        cod_GCC_EXCEPT_TABLE_SIZE = ABSOLUTE(cod_GCC_EXCEPT_TABLE_END - cod_GCC_EXCEPT_TABLE_START);
        cod_SDATA_START = .;
        build/src/main.o(.sdata*);
        build/src/engine/resource_loader.o(.sdata*);
        build/src/actors/FOO.o(.sdata*);
        build/src/game/CharacterManager.o(.sdata*);
        build/asm/entry.o(.sdata*);
        build/asm/data/cod/30A130.o(.sdata*);
        build/asm/data/cod/38A780.sdata.o(.sdata*);
        . = ALIGN(., 16);
        cod_SDATA_END = .;
        cod_SDATA_SIZE = ABSOLUTE(cod_SDATA_END - cod_SDATA_START);
    }
    cod_bss_VRAM = ADDR(.cod_bss);
    .cod_bss (NOLOAD) :
    {
        FILL(0x00000000);
        cod_SBSS_START = .;
        build/src/main.o(.sbss COMMON .scommon);
        build/src/engine/resource_loader.o(.sbss COMMON .scommon);
        build/src/actors/FOO.o(.sbss COMMON .scommon);
        build/src/game/CharacterManager.o(.sbss COMMON .scommon);
        build/asm/entry.o(.sbss COMMON .scommon);
        build/asm/data/cod/30A130.o(.sbss COMMON .scommon);
        build/asm/data/cod/0048AF00.sbss.o(.sbss COMMON .scommon);
        . = ALIGN(., 16);
        cod_SBSS_END = .;
        cod_SBSS_SIZE = ABSOLUTE(cod_SBSS_END - cod_SBSS_START);
        cod_BSS_START = .;
        build/src/main.o(.bss COMMON .scommon);
        build/src/engine/resource_loader.o(.bss COMMON .scommon);
        build/src/actors/FOO.o(.bss COMMON .scommon);
        build/src/game/CharacterManager.o(.bss COMMON .scommon);
        build/asm/entry.o(.bss COMMON .scommon);
        build/asm/data/cod/30A130.o(.bss COMMON .scommon);
        build/asm/data/cod/0048B480.bss.o(.bss COMMON .scommon);
        . = ALIGN(., 16);
        cod_BSS_END = .;
        cod_BSS_SIZE = ABSOLUTE(cod_BSS_END - cod_BSS_START);
    }
    __romPos += SIZEOF(.cod);
    __romPos = ALIGN(__romPos, 16);
    . = ALIGN(., 16);
    cod_ROM_END = __romPos;
    cod_VRAM_END = .;

    /DISCARD/ :
    {
        *(*);
    }
}
