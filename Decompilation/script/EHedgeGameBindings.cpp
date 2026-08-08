// script/EHedgeGameBindings.cpp
#include "EngineTypes.h"

void RegisterEHedgeGameScriptBindings(undefined8 param_1) {
    int iVar10;
    undefined4 *puVar8;

    // Allocate script registration table container
    puVar8 = (undefined4 *)FUN_00311cc8(0x6c4);
    *puVar8 = 0x21;
    iVar10 = (int)param_1;
    
    // Bind EHedgeGame.LoadLevel
    puVar8[0x8] = "EHedgeGame.LoadLevel";
    puVar8[0xb] = FUN_0019e7a8;

    // Bind EHedgeGame.PlaySound
    puVar8[0x15] = "EHedgeGame.PlaySound";
    puVar8[0x18] = FUN_0019dbf8;

    // Bind EHedgeGame.UnLoadLevel
    puVar8[0x2f] = "EHedgeGame.UnLoadLevel";
    puVar8[0x32] = FUN_0019d3b8;

    // Bind EHedgeGame.PlayMovie
    puVar8[0x19b] = "EHedgeGame.PlayMovie";
    puVar8[0x1a2] = FUN_0019d620;

    // Finalize registration with core engine manager
    FUN_002b9b68(param_1, 0x440ab0);
}