#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0x18]; f32 unk28; u8 pad2C[0x258]; void *unk284; u8 pad288[0xC]; s16 unk294; u8 pad296[0x2A]; f32 unk2C0; u8 pad2C4[0x6]; s16 unk2CA; } S_arg0;

extern M2C_UNK D_80BF329C;

void func_800031F0(S_arg0 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    f32 temp_f2;

    if (arg0->unk2C0 != 0.0f) {
        temp_f2 = arg0->unk28;
        if (arg0->unk2C0 <= temp_f2) {
            arg0->unk2C0 = (f32) (temp_f2 - 40.0f);
        }
        arg0->unk294 = 2;
        arg0->unk2CA = 0xFF;
        arg0->unk284 = &D_80BF329C;
        arg0->unk2C0 = (f32) (arg0->unkC + (temp_f2 - arg0->unk2C0));
    }
}
