typedef int s32;
typedef unsigned char u8;

extern "C" {
    extern void FUN_002679b8(void);
    extern void FUN_00316ae0(void*, s32, s32);
    extern void FUN_0030b310(void);
    extern void FUN_0030b720(void);
    extern s32 *FUN_00134250(void);
    extern void SetAlarm(int, void*, void*);
    extern void FUN_002680a0();
}

struct CBAR {
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;
    s32 m_unkC;
    s32 m_unk10;
    char *m_unk14;

    void FUN_0030b310(s32, s32, s32);
    void FUN_0030b720();
};

struct CFOO {
    s32 m_unk0;
    CBAR m_unk4;
    u8 m_unk1C[0x30-0x1C];
    s32 m_unk30;
    u8 m_unk34[0x50-0x34];
    s32 m_unk50;

    /* -------- vtbl[0]  */ /* -------- */ /* type_info function */
    /* 00463BD4 vtbl[1]  */ /* 00268128 */ virtual ~CFOO();
    /* 00463BDC vtbl[2]  */ /* 00268248 */ virtual void CFOO_virt_2();
    /* 00463BE4 vtbl[3]  */ /* 002681B0 */ virtual void CFOO_virt_3();
    /* 00463BEC vtbl[4]  */ /* 00268208 */ virtual void CFOO_virt_4();
    /* 00463BF4 vtbl[5]  */ /* 002682F0 */ virtual void CFOO_virt_5();
    /* 00463BFC vtbl[6]  */ /* 00268318 */ virtual void CFOO_virt_6();
    /* 00463C04 vtbl[7]  */ /* 002683B0 */ virtual void CFOO_virt_7();
    /* 00463C0C vtbl[8]  */ /* 002678F0 */ virtual void CFOO_virt_8();
    /* 00463C14 vtbl[9]  */ /* 00268450 */ virtual void CFOO_virt_9();
    /* 00463C1C vtbl[10] */ /* 00268588 */ virtual void CFOO_virt_10();
    /* 00463C24 vtbl[11] */ /* 002686A0 */ virtual void CFOO_virt_11();
    /* 00463C2C vtbl[12] */ /* 00268848 */ virtual void CFOO_virt_12();
    /* 00463C34 vtbl[13] */ /* 00267CC0 */ virtual void CFOO_virt_13();
    /* 00463C3C vtbl[14] */ /* 00268790 */ virtual void CFOO_virt_14();
    /* 00463C44 vtbl[15] */ /* 00268900 */ virtual void CFOO_virt_15();
    /* 00463C4C vtbl[16] */ /* 00268998 */ virtual void CFOO_virt_16();
    /* 00463C54 vtbl[17] */ /* 00268A30 */ virtual void CFOO_virt_17();
    /* 00463C5C vtbl[18] */ /* 00268080 */ virtual void CFOO_virt_18();
};


void CFOO::CFOO_virt_2(void) {
    
    CBAR *unk4 = &this->m_unk4;
    
    FUN_002679b8();
    FUN_00316ae0(&this->m_unk50, 0x20, 0); 

    unk4->m_unk14 = "Resource Loader";
    unk4->FUN_0030b310(0x60, 0x8000, 0);
    unk4->FUN_0030b720();
    
    SetAlarm(FUN_00134250()[0] == 1 ? 0x80 : 0x78, (void*)&FUN_002680a0, this);
    this->m_unk30 = 1;
}
