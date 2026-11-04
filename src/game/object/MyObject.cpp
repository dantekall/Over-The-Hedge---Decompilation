#define NULL 0

struct UnkSubStruct {
    u16 m_unk0;
    u16 m_unk2;
    u16 m_unk4;
    u16 m_unk6;
    u16 m_unk8;
};

class UnkKlass4 {
    public:
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;

    UnkKlass4();
};

class UnkKlass14 {
    public:
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;

    UnkKlass14();
};

class UnkKlass20 {
    public:
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;

    UnkKlass20();
};

class UnkKlassE0 {
    public:
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;

    UnkKlassE0();
};

class UnkKlass138 {
    public:
    s32 m_unk0;
    s32 m_unk4;
    s32 m_unk8;
    s32 m_unkC;
    s32 m_unk10;

    UnkKlass138();
    void func_00256F78(void*);
};

class MyBaseObject {
    public:
    s32 m_unk0;
    UnkKlass4 m_unk4;
    s32 m_unk10;
    UnkKlass14 m_unk14;
    UnkKlass20 m_unk20;
    
    MyBaseObject();
    MyBaseObject(int arg1, int arg2) : m_unk0(arg1), m_unk10(arg2) {
        
    }
    
    /* 0045DF7C */
    /* vtbl[ 0] - 0x00000000 */ /* Type Info Function */
    /* vtbl[ 1] - 0x002184F0 */ virtual void MyBaseObject_Virt1();
    /* vtbl[ 2] - 0x001E48A0 */ virtual void MyBaseObject_Virt2() = 0;
    /* vtbl[ 3] - 0x001E48A0 */ virtual void MyBaseObject_Virt3() = 0;
    /* vtbl[ 4] - 0x001E48A0 */ virtual void MyBaseObject_Virt4() = 0;
    /* vtbl[ 5] - 0x001E48A0 */ virtual void MyBaseObject_Virt5() = 0;
    /* vtbl[ 6] - 0x001E48A0 */ virtual void MyBaseObject_Virt6() = 0;
    /* vtbl[ 7] - 0x001E48A0 */ virtual void MyBaseObject_Virt7() = 0;
    /* vtbl[ 8] - 0x001E48A0 */ virtual void MyBaseObject_Virt8() = 0;
    /* vtbl[ 9] - 0x001E48A0 */ virtual void MyBaseObject_Virt9() = 0;
    /* vtbl[10] - 0x001E48A0 */ virtual void MyBaseObject_Virt10() = 0;
    /* vtbl[11] - 0x001E48A0 */ virtual void MyBaseObject_Virt11() = 0;
    /* vtbl[12] - 0x00218470 */ virtual void MyBaseObject_Virt12();
    /* vtbl[13] - 0x00218480 */ virtual void MyBaseObject_Virt13();
    /* vtbl[14] - 0x00218488 */ virtual void MyBaseObject_Virt14();
    /* vtbl[15] - 0x00218498 */ virtual void MyBaseObject_Virt15();
    /* vtbl[16] - 0x002184B0 */ virtual void MyBaseObject_Virt16();
    /* vtbl[17] - 0x002184C8 */ virtual void MyBaseObject_Virt17();
    /* vtbl[18] - 0x002184D0 */ virtual void MyBaseObject_Virt18();
    /* vtbl[19] - 0x002184D8 */ virtual void MyBaseObject_Virt19();
    /* vtbl[20] - 0x002184E8 */ virtual void MyBaseObject_Virt20();
    /* vtbl[21] - 0x001E48A0 */ virtual void MyBaseObject_Virt21() = 0;
    /* vtbl[22] - 0x001E48A0 */ virtual void MyBaseObject_Virt22() = 0;
    /* vtbl[23] - 0x001E48A0 */ virtual void MyBaseObject_Virt23() = 0;
};

class MyDerivedObject : public MyBaseObject {
    public:
    s32 m_unk30;
    s32 m_unk34;
    s32 m_unk38;
    s32 m_unk3C;
    s32 m_unk40;
    s32 m_unk44;
    s32 m_unk48;
    s32 m_unk4C;
    s32 m_unk50;
    s32 m_unk54;
    s32 m_unk58;
    s32 m_unk5C;
    s32 m_unk60;
    s32 m_unk64;
    s32 m_unk68;
    s32 m_unk6C;
    s32 m_unk70;
    s32 m_unk74;
    s32 m_unk78;
    s32 m_unk7C;
    s32 m_unk80;
    s32 m_unk84;
    s32 m_unk88;
    s32 m_unk8C;
    s32 m_unk90;
    s32 m_unk94;
    s32 m_unk98;
    s32 m_unk9C;
    s32 m_unkA0;
    s32 m_unkA4;
    s32 m_unkA8;
    s32 m_unkAC;
    s32 m_unkB0;
    s32 m_unkB4;
    s32 m_unkB8;
    s32 m_unkBC;
    s32 m_unkC0;
    s32 m_unkC4;
    UnkKlass14 m_unkC8;
    UnkKlass20 m_unkD4;
    UnkKlassE0 m_unkE0;
    UnkKlassE0 m_unkEC[4];
    s32 m_unk11C;
    s32 m_unk120;
    s32 m_unk124;
    s32 m_unk128;
    s32 m_unk12C;
    s32 m_unk130;
    UnkSubStruct* m_unk134;
    UnkKlass138 m_unk138;
    
    MyDerivedObject();
    MyDerivedObject(int, UnkSubStruct*);

    /* 0045D13C */
    /* vtbl[ 0] - 00000000 */ /* Type Info Function */
    /* vtbl[ 1] * 002122A8 */ virtual void MyDerivedObject_Virt1();
    /* vtbl[ 2] * 002129C8 */ virtual void MyDerivedObject_Virt2();
    /* vtbl[ 3] * 002125D0 */ virtual void MyDerivedObject_Virt3();
    /* vtbl[ 4] * 00212A00 */ virtual void MyDerivedObject_Virt4();
    /* vtbl[ 5] * 00212D50 */ virtual void MyDerivedObject_Virt5();
    /* vtbl[ 6] * 00212E68 */ virtual void MyDerivedObject_Virt6();
    /* vtbl[ 7] * 00212E08 */ virtual void MyDerivedObject_Virt7();
    /* vtbl[ 8] * 00212B90 */ virtual void MyDerivedObject_Virt8();
    /* vtbl[ 9] * 00212A08 */ virtual void MyDerivedObject_Virt9();
    /* vtbl[10] * 00212A10 */ virtual void MyDerivedObject_Virt10();
    /* vtbl[11] * 00212F38 */ virtual void MyDerivedObject_Virt11();
    /* vtbl[12] - 00218470 */ virtual void MyBaseObject_Virt12();
    /* vtbl[13] - 00218480 */ virtual void MyBaseObject_Virt13();
    /* vtbl[14] - 00218488 */ virtual void MyBaseObject_Virt14();
    /* vtbl[15] - 00218498 */ virtual void MyBaseObject_Virt15();
    /* vtbl[16] - 002184B0 */ virtual void MyBaseObject_Virt16();
    /* vtbl[17] - 002184C8 */ virtual void MyBaseObject_Virt17();
    /* vtbl[18] - 002184D0 */ virtual void MyBaseObject_Virt18();
    /* vtbl[19] - 002184D8 */ virtual void MyBaseObject_Virt19();
    /* vtbl[20] - 002184E8 */ virtual void MyBaseObject_Virt20();
    /* vtbl[21] * 00212BC0 */ virtual void MyDerivedObject_Virt21();
    /* vtbl[22] * 00212C70 */ virtual void MyDerivedObject_Virt22();
    /* vtbl[23] * 00212D20 */ virtual void MyDerivedObject_Virt23();
};

u8 D_004A4FA0[100];

MyDerivedObject::MyDerivedObject(int arg1, UnkSubStruct* arg2) :
    MyBaseObject(arg1, 0x805C7C17)
{
    this->m_unkC4 = 0;
    this->m_unkC0 = 0;
    this->m_unk30 = 0;
    this->m_unk134 = arg2;

    if (arg2 != NULL && arg2->m_unk4) {
        arg2->m_unk6++;
    }
    
    this->m_unk11C = 0;
    this->m_unk120 = 0;
    this->m_unk124 = 0;
    this->m_unk128 = 0;
    this->m_unk12C = 0;
    this->m_unk130 = 0;

    this->m_unk138.func_00256F78(&D_004A4FA0);
}
