#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0x20]; f32 unk28; u8 pad2C[0x44]; f32 unk70; u8 pad74[0x50]; f32 unkC4; u8 padC8[0xC0]; void *unk188; u8 pad18C[0x5]; s8 unk191; s16 unk192; } S_arg0;

extern M2C_UNK D_80B007C0;
extern f32 D_80B02854;

void func_8000168C(S_arg0 *arg0) {
    arg0->unk192 = 0;
    arg0->unk70 = 0.0f;
    arg0->unk28 = (f32) (arg0->unk28 + 42.0f);
    arg0->unkC4 = (f32) D_80B02854;
    arg0->unk4 = (s32) (arg0->unk4 & ~1);
    arg0->unk191 = 0;
    arg0->unk188 = &D_80B007C0;
}
