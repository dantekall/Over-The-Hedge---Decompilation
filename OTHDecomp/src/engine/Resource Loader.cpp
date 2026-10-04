#include <stdint.h>
#include <kernel.h>
#include <tamtypes.h>

// Forward declarations for unknown types
struct ResourceSubManager;
struct ResourceBuffer;

// Reconstructing the memory layout based on assembly offsets
struct ResourceLoader {
    /* 0x00 */ void* parentInheritance;
    /* 0x04 */ int subManager[12];        // Passed to func_0030B720
    /* 0x18 */ const char* loaderName;    // Written via sw $2, 0x14($16)
    /* 0x1C */ uint8_t pad_1C[0x14];
    /* 0x30 */ uint32_t isInitialized;    // Written as '1' at the end
    /* 0x34 */ uint8_t pad_34[0x1C];
    /* 0x50 */ int bufferStruct;          // Offset 0x50 passed to func_00316AE0
};

// External variables referenced in code
extern int pluginThreadID;
extern int g_TimingMode;

// Forward declarations for external/un-decompiled functions
void FUN_002679b8(void*);
void FUN_00316ae0(void*, int, int);
void FUN_0030b310(void*, int, int, int);
void FUN_0030b720(void*);
void FUN_00134250(void);
void FUN_002680A0(void);
void FUN_003d3f28(int threadID, void* context);

void ResourceThread_ManageStatus(void* param_1)
{
    int* threadIDPtr = (int*)param_1;
    int threadStatusBuffer[12]; // Matches auStack_40 size

    ReferThreadStatus(*threadIDPtr, threadStatusBuffer);

    switch (threadStatusBuffer[0]) {
        case 4:
            WakeupThread(*threadIDPtr);
            break;
        case 8:
            ResumeThread(*threadIDPtr);
            break;
        case 0xc:
            WakeupThread(*threadIDPtr);
            pluginThreadID = *threadIDPtr;
            ResumeThread(pluginThreadID);
            break;
        case 0x10:
            FUN_003d3f28(*threadIDPtr, param_1);
            break;
        default:
            break;
    }
}

void ResourceLoader_Init(struct ResourceLoader* this_ptr)
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
    SetAlarm(alarmTime, (void (*)(int, void*))FUN_002680A0, this_ptr);

    // sw $18, 0x30($17)
    this_ptr->isInitialized = 1;
}
