// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s32 unk28;
    /* 0x2C */ s32 unk2C;
    /* 0x30 */ s32 unk30;
    /* 0x34 */ s32 unk34;
    /* 0x38 */ s32 unk38;
    /* 0x3C */ s32 unk3C;
} Func80088440Struct;

void func_80088440(Func80088440Struct *arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 temp_f10;
    s32 temp_f10_2;
    s32 temp_f10_3;

    arg0->unk4 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk18 = 0;
    arg0->unk24 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    temp_f10 = (s32) (arg1 * 65536.0f);
    arg0->unk38 = 0;
    arg0->unk3C = 0;
    temp_f10_2 = (s32) (arg2 * 65536.0f);
    arg0->unk0 = (s32) (((u32) temp_f10 >> 0x10) << 0x10);
    arg0->unk20 = (s32) (temp_f10 << 0x10);
    temp_f10_3 = (s32) (arg3 * 65536.0f);
    arg0->unk28 = (s32) (temp_f10_2 & 0xFFFF);
    arg0->unk8 = (u32) ((u32) temp_f10_2 >> 0x10);
    arg0->unk14 = (s32) (((u32) temp_f10_3 >> 0x10) << 0x10);
    arg0->unk34 = (s32) (temp_f10_3 << 0x10);
    arg0->unk1C = 1;
}
