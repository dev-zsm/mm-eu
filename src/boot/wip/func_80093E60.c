// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    s32 unk3C;
} Func80093E60;

void func_80093E60(Func80093E60 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 temp_f10;
    s32 temp_f10_2;
    s32 temp_f10_3;

    arg0->unk0 = 0;
    arg0->unk14 = 0;
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk20 = 0;
    temp_f10 = (s32) (arg1 * 65536.0f);
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    temp_f10_2 = (s32) (arg2 * 65536.0f);
    arg0->unk30 = 0;
    arg0->unk34 = 0;
    temp_f10_3 = (s32) (arg3 * 65536.0f);
    arg0->unk18 = (s32) ((((u32) temp_f10 >> 0x10) << 0x10) | ((u32) temp_f10_2 >> 0x10));
    arg0->unk38 = (s32) ((temp_f10 << 0x10) | ((u32) (temp_f10_2 << 0x10) >> 0x10));
    arg0->unk1C = (s32) ((((u32) temp_f10_3 >> 0x10) << 0x10) + 1);
    arg0->unk0 = 0x10000;
    arg0->unk14 = 0x10000;
    arg0->unk3C = (s32) (temp_f10_3 << 0x10);
    arg0->unk8 = 1;
}
