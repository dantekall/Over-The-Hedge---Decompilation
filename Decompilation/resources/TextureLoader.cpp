// resources/TextureLoader.cpp
#include "EngineTypes.h"

unsigned int InitTextureLoader(undefined8 param_1) {
    unsigned int statusFlag;
    long lVar2;
      
    lVar2 = AllocMemoryBlock((int)param_1 + 0x24, 0x400, 0);
    if (lVar2 == 0) {
        statusFlag = 0;
    } else {
        *(char **)((int)param_1 + 0x14) = "Texture Loader";
        lVar2 = SetupResourceQueue(param_1, 0x5b, 0x1000, 0);
        statusFlag = 0;
        if (lVar2 != 0) {
            EnableResourceQueue(param_1);
            statusFlag = 1;
        }
    }
    return statusFlag;
}