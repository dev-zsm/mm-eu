// FLAGS: -g
// COMPILER: ido53
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[2];
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u32 unk8;
    /* 0x0C */ u32 unkC;
    /* 0x10 */ u32 unk10;
} FlashMsg;

extern u8 D_801F48C0[];
extern u32 D_801F48CC;

void func_80088070(s32, s32, s32);
s32 func_8008EFD0(void *, void *, s32);
void func_80092250(void *, u32, u32 *);
void func_80093D50(void *, u32, u32);
u32 func_80187910(u32);

s32 func_801883CC(FlashMsg *arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5) {
    s32 sp24;
    u32 sp20;
    u32 sp1C;
    u32 sp18;

    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0xF0000000);
    func_80092250(D_801F48C0, D_801F48CC, &sp20);
    arg0->unk2 = arg1;
    arg0->unk4 = arg5;
    arg0->unk8 = arg3;
    sp1C = arg2 + arg4 - 1;
    if ((sp1C & 0xF00) != (arg2 & 0xF00)) {
        sp18 = 0x100 - (arg2 & 0xFF);
        arg4 -= sp18;
        arg0->unk10 = sp18 << 7;
        arg0->unkC = func_80187910(arg2);
        func_8008EFD0(D_801F48C0, arg0, 0);
        func_80088070(arg5, 0, 1);
        arg2 = (arg2 + 0x100) & 0xF00;
        arg0->unk8 += arg0->unk10;
    }
    while (arg4 > 0x100) {
        sp18 = 0x100;
        arg4 -= 0x100;
        arg0->unk10 = sp18 << 7;
        arg0->unkC = func_80187910(arg2);
        func_8008EFD0(D_801F48C0, arg0, 0);
        func_80088070(arg5, 0, 1);
        arg2 += 0x100;
        arg0->unk8 += arg0->unk10;
    }
    arg0->unk10 = arg4 << 7;
    arg0->unkC = func_80187910(arg2);
    sp24 = func_8008EFD0(D_801F48C0, arg0, 0);
    return sp24;
}
