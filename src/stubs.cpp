#include "types.h"
#include "classes.h"

// Required global new/delete operators for -nostdlib C++ support
void* operator new(unsigned long size) throw() { return nullptr; }
void* operator new[](unsigned long size) throw() { return nullptr; }
void operator delete(void* ptr) noexcept {}
void operator delete(void* ptr, unsigned long size) noexcept {}
void operator delete[](void* ptr) noexcept {}
void operator delete[](void* ptr, unsigned long size) noexcept {}

extern "C" {
    // Stubs for functions jumped to by entry.s and resource_loader.cpp
    void FUN_003d9100() {}
    void FlushCache() {}
    void FUN_0027cb00() {}
    void FUN_0027ca68() {}
    void FUN_00100258() {}
    void SetAlarm() {}
    void FUN_002679b8() {}
    void FUN_00316ae0() {}
    void FUN_00134250() {}
    void FUN_002680a0() {}
}

// BAR implementation
BAR::BAR() {}
BAR::~BAR() {}
void BAR::BAR_virt_2() {}
void BAR::BAR_virt_3() {}
void BAR::BAR_virt_4() {}
void BAR::BAR_virt_5() {}
void BAR::BAR_virt_6() {}
void BAR::BAR_virt_7() {}
void BAR::BAR_virt_8() {}
void BAR::BAR_virt_9() {}
void BAR::BAR_virt_10() {}
void BAR::BAR_virt_11() {}
void BAR::BAR_virt_12() {}
void BAR::BAR_virt_13() {}
void BAR::BAR_virt_14() {}
void BAR::BAR_virt_15() {}
void BAR::BAR_virt_16() {}
void BAR::BAR_virt_17() {}
void BAR::BAR_virt_18() {}

// CBAR implementation
CBAR::CBAR() {}
CBAR::~CBAR() {}
int CBAR::FUN_0030b310(int, int, int) { return 0; }
int CBAR::FUN_0030b720() { return 0; }

// BAZ implementation
BAZ::BAZ() {}
