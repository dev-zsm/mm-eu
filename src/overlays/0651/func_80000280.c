#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0x18]; f32 unk28; u8 pad2C[0x160]; f32 unk18C; f32 unk190; f32 unk194; u8 pad198[0x1A0]; s16 unk338; s16 unk33A; } S_arg0;

f32 func_800FEB44(s16);                             /* extern */
f32 func_800FEB84(s16);                             /* extern */
extern f32 D_80C04084;
extern f32 D_80C04088;

void func_80000280(S_arg0 *arg0, M2C_UNK arg1) {
    f32 temp_f2;
    f32 temp_f2_2;

    arg0->unk338 = (s16) (arg0->unk338 + 0x320);
    arg0->unk33A = (s16) (arg0->unk33A + 0x3E8);
    temp_f2 = (func_800FEB44(arg0->unk338) * D_80C04084) + 1.0f;
    arg0->unk194 = temp_f2;
    arg0->unk190 = temp_f2;
    temp_f2_2 = (func_800FEB84(arg0->unk338) * D_80C04088) + 1.0f;
    arg0->unk18C = (f32) (temp_f2_2 * temp_f2_2);
    arg0->unk28 = (f32) ((func_800FEB84(arg0->unk338) * 25.0f) + arg0->unkC);
}
