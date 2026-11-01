#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s8 unk10;
    /* 0x11 */ s8 unk11;
    /* 0x12 */ s8 unk12;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
} Arg;

typedef struct {
    u8 pad[0x150];
    s16 unk150;
} Other;

extern void func_8008B7F0(s32);
extern void func_80090000(s32);
extern void func_800922A0(s32);
extern void func_80095AA0(f32);
extern void func_80095AF0(f32);
extern s8 D_80096CC0;
extern s32 D_80096D00;
extern Other *D_801EB7E0;

void func_80177440(Arg *arg0) {
    s32 temp_a1;

    temp_a1 = arg0->unk4;
    if (temp_a1 != 0) {
        func_80090000(temp_a1);
        arg0->unk12 = arg0->unk11;
        if ((D_801EB7E0->unk150 == 0) && (arg0->unk8 != 0) && (*(s32 *)&D_80096D00 == 0)) {
            D_80096CC0 = 1;
            func_8008B7F0(arg0->unk8);
            func_800922A0(arg0->unkC);
            func_80095AF0(arg0->unk14);
            func_80095AA0(arg0->unk18);
            arg0->unk8 = 0;
        }
    }
    arg0->unk10 = 0;
}
