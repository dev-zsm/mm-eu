// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
} Mtx;

extern f32 sqrtf(f32 x);
void func_8008B7A0(void);

void func_8008B870(Mtx *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8, f32 arg9) {
    f32 sp68;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f16;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f24_2;
    f32 temp_f26;
    f32 temp_f26_2;
    f32 temp_f28;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;

    func_8008B7A0();
    temp_f2 = arg4 - arg1;
    temp_f12 = arg5 - arg2;
    temp_f14 = arg6 - arg3;
    temp_f16 = (f32) (-1.0 / (f64) sqrtf((temp_f2 * temp_f2) + (temp_f12 * temp_f12) + (temp_f14 * temp_f14)));
    temp_f28 = temp_f2 * temp_f16;
    sp54 = temp_f12 * temp_f16;
    sp50 = temp_f14 * temp_f16;
    sp68 = sp50;
    sp4C = (arg8 * sp50) - (arg9 * sp54);
    temp_f24 = (arg9 * temp_f28) - (arg7 * sp50);
    sp50 = temp_f24;
    temp_f26 = (arg7 * sp54) - (arg8 * temp_f28);
    sp58 = temp_f26;
    temp_f20 = (f32) (1.0 / (f64) sqrtf((sp4C * sp4C) + (temp_f24 * temp_f24) + (temp_f26 * temp_f26)));
    temp_f22 = sp4C * temp_f20;
    temp_f24_2 = temp_f24 * temp_f20;
    temp_f26_2 = temp_f26 * temp_f20;
    temp_f2_2 = (sp54 * temp_f26_2) - (sp68 * temp_f24_2);
    temp_f12_2 = (sp68 * temp_f22) - (temp_f28 * temp_f26_2);
    temp_f14_2 = (temp_f28 * temp_f24_2) - (sp54 * temp_f22);
    temp_f20_2 = (f32) (1.0 / (f64) sqrtf((temp_f2_2 * temp_f2_2) + (temp_f12_2 * temp_f12_2) + (temp_f14_2 * temp_f14_2)));
    arg7 = temp_f2_2 * temp_f20_2;
    arg0->unk0 = temp_f22;
    arg0->unk10 = temp_f24_2;
    arg0->unk20 = temp_f26_2;
    temp_f0 = temp_f12_2 * temp_f20_2;
    temp_f2_3 = temp_f14_2 * temp_f20_2;
    arg0->unk30 = (f32) -((arg1 * temp_f22) + (arg2 * temp_f24_2) + (arg3 * temp_f26_2));
    arg0->unk14 = temp_f0;
    arg0->unk24 = temp_f2_3;
    arg0->unk8 = temp_f28;
    arg0->unk18 = sp54;
    arg0->unk4 = arg7;
    arg0->unk28 = sp68;
    arg0->unkC = 0.0f;
    arg0->unk1C = 0.0f;
    arg0->unk2C = 0.0f;
    arg0->unk34 = (f32) -((arg1 * arg7) + (arg2 * temp_f0) + (arg3 * temp_f2_3));
    arg0->unk3C = 1.0f;
    arg0->unk38 = (f32) -((arg1 * temp_f28) + (arg2 * sp54) + (arg3 * sp68));
}
