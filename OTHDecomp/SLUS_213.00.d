build/SLUS_213.00.elf: \
    build/src/main.o \
    build/src/engine/resource_loader.o \
    build/src/actors/FOO.o \
    build/src/game/CharacterManager.o \
    build/asm/entry.o \
    build/asm/data/cod/30A130.o \
    build/asm/data/cod/312800.data.o \
    build/asm/data/cod/321200.rodata.o \
    build/asm/data/cod/38A680.gcc_except_table.o \
    build/asm/data/cod/38A780.sdata.o \
    build/asm/data/cod/0048AF00.sbss.o \
    build/asm/data/cod/0048B480.bss.o
build/src/main.o:
build/src/engine/resource_loader.o:
build/src/actors/FOO.o:
build/src/game/CharacterManager.o:
build/asm/entry.o:
build/asm/data/cod/30A130.o:
build/asm/data/cod/312800.data.o:
build/asm/data/cod/321200.rodata.o:
build/asm/data/cod/38A680.gcc_except_table.o:
build/asm/data/cod/38A780.sdata.o:
build/asm/data/cod/0048AF00.sbss.o:
build/asm/data/cod/0048B480.bss.o:
-include build/src/main.d build/src/engine/resource_loader.d build/src/actors/FOO.d build/src/game/CharacterManager.d build/asm/entry.d build/asm/data/cod/30A130.d build/asm/data/cod/312800.data.d build/asm/data/cod/321200.rodata.d build/asm/data/cod/38A680.gcc_except_table.d build/asm/data/cod/38A780.sdata.d build/asm/data/cod/0048AF00.sbss.d build/asm/data/cod/0048B480.bss.d
