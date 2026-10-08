#pragma once
#include <cstdint>

struct ResourceLoader {
    void* parentInheritance;
    int subManager[12];
    const char* loaderName;
    std::uint8_t pad_1C[0x14];
    std::uint32_t isInitialized;
    std::uint8_t pad_34[0x1C];
    int bufferStruct;
};

void ResourceLoader_Init(ResourceLoader* this_ptr);
