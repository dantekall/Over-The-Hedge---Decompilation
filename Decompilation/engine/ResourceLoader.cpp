#include <cstdint>

// Forward declarations for unknown types
struct ResourceSubManager;
struct ResourceBuffer;

// Reconstructing the memory layout based on assembly offsets
struct ResourceLoader {
    /* 0x00 */ void* parentInheritance;
    /* 0x04 */ int subManager[12];       // Passed to func_0030B720
    /* 0x18 */ const char* loaderName;   // Written via sw $2, 0x14($16)
    /* 0x1C */ std::uint8_t pad_1C[0x14];
    /* 0x30 */ std::uint32_t isInitialized; // Written as '1' at the end
    /* 0x34 */ std::uint8_t pad_34[0x1C];
    /* 0x50 */ int bufferStruct;         // Offset 0x50 passed to func_00316AE0
};

// Externs for the functions we haven't decompiled yet
extern "C" {
    void FUN_002679b8(ResourceLoader* loader);
    void FUN_00316ae0(void* buffer, int size, int flag);
    void FUN_0030b310(void* manager, int size, int flags, int mode);
    void FUN_0030b720(void* manager);
    void FUN_00134250();
    void SetAlarm(int time, void (*callback)(ResourceLoader*), ResourceLoader* context);
    void func_002680A0(ResourceLoader* loader); // The callback
}

// Global timing flag (represented by D_00463B60 in the ternary logic)
extern int g_TimingMode;

void ResourceLoader_Init(ResourceLoader* this_ptr)
{
    // jal func_002679B8
    FUN_002679b8(this_ptr);

    // jal func_00316AE0 (args: this+0x50, 0x20, 0)
    FUN_00316ae0(&this_ptr->bufferStruct, 0x20, 0);

    // sw $2, 0x14($16)
    this_ptr->loaderName = "Resource Loader";

    // jal func_0030B310
    FUN_0030b310(&this_ptr->subManager, 0x60, 0x8000, 0);

    // jal func_0030B720
    FUN_0030b720(&this_ptr->subManager);

    // jal func_00134250
    FUN_00134250();

    // Reconstructing the movn/xori MIPS logic that Ghidra missed
    int alarmTime = (g_TimingMode == 1) ? 0x78 : 0x80;
    SetAlarm(alarmTime, func_002680A0, this_ptr);

    // sw $18, 0x30($17)
    this_ptr->isInitialized = 1;
}
