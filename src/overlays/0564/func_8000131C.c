#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0xC]; f32 unkC; u8 pad10[0x18]; f32 unk28; u8 pad2C[0x3C]; f32 unk68; u8 pad6C[0x26C]; void *unk2D8; u8 pad2DC[0x4C]; u16 unk328; u8 pad32A[0x16]; s16 unk340; u8 pad342[0x6]; s32 unk348; s16 unk34C; u8 pad34E[0x1A]; f32 unk368; u8 pad36C[0x2]; s16 unk36E; } S_arg0;

M2C_UNK func_800FFBF8(u8 *, f32, M2C_UNK, f32); /* extern */
M2C_UNK func_8013C01C(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
extern M2C_UNK D_80BB0D9C;
extern M2C_UNK D_80BB190C;
extern f32 D_80BB1B0C;

void func_8000131C(S_arg0 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    temp_f0 = arg0->unk368;
    arg0->unk340 = (s16) (arg0->unk340 + arg0->unk34C);
    if (temp_f0 >= 1.0f) {
        arg0->unk368 = 1.0f;
        arg0->unk68 = 5.0f;
    } else {
        arg0->unk68 = 5.0f;
        arg0->unk368 = (f32) (temp_f0 + D_80BB1B0C);
    }
    if ((arg0->unkC + 50.0f) < arg0->unk28) {
        func_800FFBF8((u8 *)arg0 + 0x68, 0.0f, 0x3E4CCCCD, 1.0f);
        arg0->unk348 = 0xA;
        func_8013C01C((u8 *)arg0 + 0x144, &D_80BB190C, 0xA);
        arg0->unk328 = (u16) (arg0->unk328 | 2);
        arg0->unk36E = 0;
        arg0->unk2D8 = &D_80BB0D9C;
    }
}
