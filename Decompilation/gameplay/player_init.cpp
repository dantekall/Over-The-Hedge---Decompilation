// gameplay/PlayerCharacterInit.cpp
#include "EngineTypes.h"

void InitPlayer1Character(undefined4 *param_1, undefined4 *param_2, undefined4 *param_3) {
    undefined4 uVar1;
    undefined1 auStack_90 [32];
    undefined1 auStack_70 [32];
    undefined1 auStack_50 [32];

    FUN_0013a680(auStack_90);
    FUN_00254840(auStack_70, auStack_90, 0x429318);
    uVar1 = FUN_00255b88(auStack_70);
    *param_2 = uVar1;
    
    FUN_00254840(auStack_50, auStack_90, 0x429330);
    FUN_00256f78(auStack_70, auStack_50);
    FUN_00256ed0(auStack_50, 2);
    
    uVar1 = FUN_00255b88(auStack_70);
    *param_3 = uVar1;
    *param_1 = DAT_0048b3f8;
    
    FUN_00256ed0(auStack_70, 2);
    FUN_00256ed0(auStack_90, 2);
}