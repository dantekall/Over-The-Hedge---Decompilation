 #include <cstdint>

// PS2 Hardware synchronization macro stub
inline void SYNC(int mode) {
    // MIPS R5900 sync instruction wrapper
    __asm__ volatile("sync.p" : : : "memory");
}

// Helper stub for sub-calculations
extern int16_t FUN_003cfd40(uint64_t v5, int32_t v4, int32_t v3);

int32_t SetupGraphicsPacket(uint64_t* packetBuffer, int16_t param2, uint16_t param3, int16_t param4, int16_t param5, int16_t param6) {
    int16_t sVar1;
    uint64_t uVar2;
    int32_t height = (int32_t)((uint32_t)param3 << 16) >> 16;
    uint64_t uVar5 = (uint64_t)(uint32_t)param2;
    int32_t width = (int32_t)param4;
    uint64_t uVar6 = (uint64_t)(uint32_t)param5;
    
    packetBuffer[1] = 0x4D;
    packetBuffer[0] = ((uint64_t)((int32_t)((uint32_t)param3 << 16) >> 22) & 0x3F) << 16 | (uVar5 & 0x0F) << 24;
    packetBuffer[3] = 0x4F;
    
    if (uVar6 == 0) {
        sVar1 = FUN_003cfd40(uVar5, height, width);
        uVar2 = (uint64_t)(uint16_t)sVar1 | ((uint64_t)(uint32_t)param6 & 0x0F) << 24 | 0x100000000ULL;
    } else {
        sVar1 = FUN_003cfd40(uVar5, height, width);
        uVar2 = (uint64_t)(uint16_t)sVar1 | ((uint64_t)(uint32_t)param6 & 0x0F) << 24;
    }
    
    packetBuffer[2] = uVar2;
    packetBuffer[5] = 0x19;
    packetBuffer[4] = (0x800ULL - (uint64_t)((uint16_t)param3 >> 1)) * 0x10 | (0x800ULL - (uint64_t)(width >> 1)) << 36;
    packetBuffer[7] = 0x41;
    packetBuffer[6] = (uint64_t)(height - 1) << 16 | (uint64_t)(width - 1) << 48;
    packetBuffer[9] = 0x1A;
    packetBuffer[8] |= 1;
    packetBuffer[11] = 0x46;
    packetBuffer[10] |= 1;
    packetBuffer[13] = 0x45;
    
    if ((uVar5 & 2) == 0) {
        uVar5 = packetBuffer[12] & ~1ULL;
    } else {
        uVar5 = packetBuffer[12] | 1ULL;
    }
    packetBuffer[12] = uVar5;
    packetBuffer[15] = 0x48;
    
    if (uVar6 == 0) {
        uVar5 = 0x30000;
    } else {
        uVar5 = (uVar6 & 3) << 17 | 0x10000;
    }
    
    packetBuffer[14] = uVar5;
    SYNC(0);
    return 8;
}
