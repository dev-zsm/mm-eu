// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x48]; void *unk48; f32 unk4C; u8 pad50[0x14]; void *unk64; } S_arg1;
typedef struct { u8 pad0[0x30]; s16 unk30; u8 pad32[0x36]; f32 unk68; u8 pad6C[0x4]; f32 unk70; f32 unk74; u8 pad78[0x2FC]; u16 unk374; u8 pad376[0x28]; s16 unk39E; } S_temp_s0;

f32 func_800FEB44();                     /* extern */
s16 func_80180F74(f32, f32);                        /* extern */
f32 func_80A7A12C();                          /* extern */
extern M2C_UNK D_80A79710;

s32 func_80000C2C(s32 arg0, S_arg1 *arg1) {
    f32 temp_f0;
    s32 sp20;
    f32 temp_f2;
    s16 temp_v0;
    S_temp_s0 *temp_s0;

    temp_s0 = arg1->unk48;
    sp20 = 0;
    temp_s0->unk74 = -1.0f;
    arg1->unk64 = &D_80A79710;
    temp_s0->unk374 = (u16) (temp_s0->unk374 | 0x2000);
    temp_f0 = func_80A7A12C(temp_s0);
    temp_f2 = temp_s0->unk70;
    if ((arg1->unk4C < (temp_f2 * temp_f2)) || (temp_f0 <= 0.0f)) {
        sp20 = 1;
    } else {
        temp_v0 = func_80180F74(-temp_s0->unk68, func_800FEB44((s16) (temp_s0->unk30 * -1), arg1) * temp_s0->unk70);
        temp_s0->unk30 = temp_v0;
        temp_s0->unk39E = temp_v0;
    }
    return sp20;
}
