
#pragma once

typedef unsigned char u8;
typedef int s32;

struct BAR {
    u8 m_unk0[0x88];
    BAR();
    virtual ~BAR();
    virtual void BAR_virt_2();
    virtual void BAR_virt_3();
    virtual void BAR_virt_4();
    virtual void BAR_virt_5();
    virtual void BAR_virt_6();
    virtual void BAR_virt_7();
    virtual void BAR_virt_8();
    virtual void BAR_virt_9();
    virtual void BAR_virt_10();
    virtual void BAR_virt_11();
    virtual void BAR_virt_12();
    virtual void BAR_virt_13();
    virtual void BAR_virt_14();
    virtual void BAR_virt_15();
    virtual void BAR_virt_16();
    virtual void BAR_virt_17();
    virtual void BAR_virt_18();
};

struct BAZ {
    s32 m_unk0;
    BAZ();
};

struct FOO : public BAR {
    BAZ m_unk8C;
    BAZ m_unk90;
    s32 m_unk94;
    s32 m_unk98;
    s32 m_unk9C;
    s32 m_unkA0;
    s32 m_unkA4;
    s32 m_unkA8;
    s32 m_unkAC;
    FOO();
};

extern FOO* g_foo;
