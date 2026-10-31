#include "types.h"

struct BAR {
    /* 0x00 */ u8 m_unk0[0x88];

    BAR();
    /* -------- vtbl[0]  */ /* type_info function */
    // /* 00290D38 vtbl[1]  */ virtual ~BAR();
    /* 0028FC18 vtbl[2]  */ virtual void BAR_virt_2();
    /* 00290E78 vtbl[3]  */ virtual void BAR_virt_3();
    /* 00290E80 vtbl[4]  */ virtual void BAR_virt_4();
    /* 0028FF48 vtbl[5]  */ virtual void BAR_virt_5();
    /* 002904E8 vtbl[6]  */ virtual void BAR_virt_6();
    /* 00290F98 vtbl[7]  */ virtual void BAR_virt_7();
    /* 0028FD00 vtbl[1]  */ virtual void BAR_virt_8();
    /* 00290CF0 vtbl[8]  */ virtual void BAR_virt_9();
    /* 00290CF8 vtbl[9]  */ virtual void BAR_virt_10();
    /* 00290D00 vtbl[10] */ virtual void BAR_virt_11();
    /* 00290D08 vtbl[11] */ virtual void BAR_virt_12();
    /* 00290D20 vtbl[12] */ virtual void BAR_virt_13();
    /* 00290D30 vtbl[13] */ virtual void BAR_virt_14();
    /* 00290660 vtbl[14] */ virtual void BAR_virt_15();
    /* 00290F18 vtbl[15] */ virtual void BAR_virt_16();
    /* 002907C0 vtbl[16] */ virtual void BAR_virt_17();
    /* 002909D0 vtbl[17] */ virtual void BAR_virt_18();
};

struct BAZ {
    /* 0x00 */ s32 m_unk0;
    BAZ();
};

struct FOO : public BAR {
public:
    /* 0x8C */ BAZ m_unk8C;
    /* 0x90 */ BAZ m_unk90;
    s32 m_unk94;
    s32 m_unk98;
    s32 m_unk9C;
    s32 m_unkA0;
    s32 m_unkA4;
    s32 m_unkA8;
    s32 m_unkAC;
    FOO();
};

FOO* g_foo;

FOO::FOO() {
    g_foo = this;
    this->m_unkAC = 0;
}
