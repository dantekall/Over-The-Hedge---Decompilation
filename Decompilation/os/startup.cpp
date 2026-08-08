// os/startup.cpp
extern "C" void entry(void) {
    // Platform initialization and hardware cache flushing
    DAT_00412e98 = 0;
    SYNC(0x10);
    // Memory zero-clear loops...
    FlushCache(0);
    EI();
    // Launch primary game systems
    FUN_00100258(void);
	
  undefined4 uVar1;
  undefined8 extraout_a0;
  undefined4 *puVar2;
  
  SignalSema(*DAT_00412e98);
  syscall(0x23);
  puVar2 = (undefined4 *)extraout_a0;
  FUN_002836f0();
  *puVar2 = &DAT_004216c8;
  FUN_003159a8(puVar2 + 0x46);
  FUN_003159a8(puVar2 + 0x47);
  puVar2[0x4c] = 0;
  puVar2[0x4b] = 0;
  puVar2[0x4d] = 0;
  puVar2[0x4f] = 0;
  puVar2[0x4e] = 0;
  puVar2[0x51] = 0;
  puVar2[0x50] = 0;
  puVar2[0x53] = 0;
  puVar2[0x52] = 0;
  FUN_003141e0(puVar2 + 0x54);
  puVar2[0x57] = &DAT_004218f8;
  FUN_0027ebb0(puVar2 + 0x58);
  FUN_00329670(puVar2 + 0x78,0x20);
  FUN_003141e0(puVar2 + 0x7d);
  DAT_0048a780 = DAT_0048a780 + 1;
  puVar2[0x44] = 0x200;
  puVar2[0x45] = 0;
  puVar2[0x49] = 0;
  puVar2[0x48] = 0;
  puVar2[0x4a] = 0;
  *(undefined8 *)(puVar2 + 0x34) = 0;
  puVar2[0x36] = 0;
  puVar2[0x41] = 0xffffffff;
  puVar2[0x42] = 0;
  puVar2[0x43] = 0;
  *(ulong *)(puVar2 + 0x20) = *(ulong *)(puVar2 + 0x20) & 0x11017ffffffff | 0x1101700000000;
  uVar1 = DAT_004a96b8;
  *(undefined8 *)(puVar2 + 0x37) = _DAT_004a96b0;
  puVar2[0x39] = uVar1;
  puVar2[0x40] = 0;
  FUN_00329798(puVar2 + 0x78,0);
  FUN_00285070(extraout_a0,0x2f);
  FUN_00285028(extraout_a0,0x10);
  return extraout_a0;
}