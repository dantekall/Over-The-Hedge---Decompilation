struct BAR {
    /* 0x00 */ u8 m_unk0[0x88];
    BAR();
    virtual int some_virt();
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
