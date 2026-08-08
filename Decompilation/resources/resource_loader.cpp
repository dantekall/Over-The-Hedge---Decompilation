// resources/ResourceLoader.cpp
#include "EngineTypes.h"

void InitResourceLoader(undefined8 param_1) {
    int *piVar1;
    undefined8 uVar2;
    int iVar3;
      
    iVar3 = (int)param_1;
    ParseResourceIndexTable(); // Formerly FUN_002679b8
    
    // Allocate resource management buffer
    AllocMemoryBlock(iVar3 + 0x50, 0x20, 0);
    *(char **)(iVar3 + 0x18) = "Resource Loader";
    
    // Setup asynchronous file streaming queues
    SetupResourceQueue(iVar3 + 4, 0x60, 0x8000, 0);
    EnableResourceQueue(iVar3 + 4);
    
    piVar1 = (int *)GetHardwareConfigFlag();
    uVar2 = (*piVar1 != 1) ? 0x78 : 0x80;
    
    SetAlarm(uVar2, 0x2680a0, param_1);
    *(undefined4 *)(iVar3 + 0x30) = 1;
}