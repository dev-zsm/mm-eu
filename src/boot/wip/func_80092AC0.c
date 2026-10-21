// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    void *unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
    u8 unk8;
    u8 unk9;
    u32 unkC;
    u32 unk10;
} Obj;

extern s32 D_80098310;
extern Obj *D_8009807C;
extern Obj D_8009E9E0;
extern u8 D_8009E9F4[];

extern void func_8008C380(void);
extern void func_8008C3C4(void);
extern void func_800897D0(void *p, s32 n);
extern u32 func_80091C00(u32 a);
extern void func_80091C70(u32 a);

Obj *func_80092AC0(void) {
    Obj *s0;
    u32 v;
    u32 old14;
    u32 old1c;
    u32 old20;
    u32 old18;

    func_8008C380();
    if (D_80098310 == 0) {
        func_8008C3C4();
        return &D_8009E9E0;
    }
    D_80098310 = 0;
    s0 = &D_8009E9E0;
    s0->unk4 = 0;
    s0->unkC = 0xB0000000;
    s0->unk9 = 0;
    s0->unk10 = 0;
    func_800897D0(D_8009E9F4, 0x60);

    while (*(u32 *)0xA4600010 & 3) {
    }
    old14 = *(u32 *)0xA4600014;
    old1c = *(u32 *)0xA460001C;
    old20 = *(u32 *)0xA4600020;
    old18 = *(u32 *)0xA4600018;
    *(u32 *)0xA4600014 = 0xFF;
    *(u32 *)0xA460001C = 0;
    *(u32 *)0xA4600020 = 3;
    *(u32 *)0xA4600018 = 0xFF;
    v = *(u32 *)(s0->unkC | 0xA0000000);
    s0->unk6 = (v >> 16) & 0xF;
    s0->unk7 = (v >> 20) & 0xF;
    s0->unk8 = v >> 8;
    s0->unk5 = v;
    *(u32 *)0xA4600014 = old14;
    *(u32 *)0xA460001C = old1c;
    *(u32 *)0xA4600020 = old20;
    *(u32 *)0xA4600018 = old18;
    v = func_80091C00(old1c);
    s0->unk0 = D_8009807C;
    D_8009807C = s0;
    func_80091C70(v);
    func_8008C3C4();
    return s0;
}
