#include "oth/types.h"
#include "oth/globals.h"

struct ResourceLoader {
    void* parentInheritance;
    int subManager[12];
    const char* loaderName;
    std::uint8_t pad_1C[0x14];
    std::uint32_t isInitialized;
    std::uint8_t pad_34[0x1C];
    int bufferStruct;
};

extern "C" {
    void FUN_002679b8(ResourceLoader* loader);
    void FUN_00316ae0(void* buffer, int size, int flag);
    void FUN_0030b310(void* manager, int size, int flags, int mode);
    void FUN_0030b720(void* manager);
    void FUN_00134250();
    void SetAlarm(int time, void (*callback)(ResourceLoader*), ResourceLoader* context);
    void func_002680A0(ResourceLoader* loader);
}

extern "C" void ResourceLoader_Init(ResourceLoader* this_ptr) {
    FUN_002679b8(this_ptr);
    FUN_00316ae0(&this_ptr->bufferStruct, 0x20, 0);
    this_ptr->loaderName = "Resource Loader";
    FUN_0030b310(&this_ptr->subManager, 0x60, 0x8000, 0);
    FUN_0030b720(&this_ptr->subManager);
    FUN_00134250();

    int alarmTime = (g_TimingMode == 1) ? 0x78 : 0x80;
    SetAlarm(alarmTime, func_002680A0, this_ptr);

    this_ptr->isInitialized = 1;
}
