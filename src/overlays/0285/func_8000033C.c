// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
#include "m2c_compat.h"

typedef struct { f32 unk0; f32 unk4; f32 unk8; } S_arg2;
typedef struct { u8 pad0[0x1C]; s32 unk1C; } S_arg1;
typedef struct { u8 pad0[0x2E]; s16 unk2E; u8 pad30[0x6]; s16 unk36; f32 unk38; } S_temp_v1;

extern f32 D_809C42E0;

void func_8000033C(s32 arg0, S_arg1 *arg1, S_arg2 *arg2) {
    s32 temp_v0;
    S_temp_v1 *temp_v1;

    temp_v0 = arg0 << 6;
    M2C_FIELD((M2C_FIELD(arg1, s32 *, 0x1C) + temp_v0), s16 *, 0x30) = (s16) (s32) arg2->unk0;
    M2C_FIELD((M2C_FIELD(arg1, s32 *, 0x1C) + temp_v0), s16 *, 0x32) = (s16) (s32) arg2->unk4;
    M2C_FIELD((M2C_FIELD(arg1, s32 *, 0x1C) + temp_v0), s16 *, 0x34) = (s16) (s32) arg2->unk8;
    temp_v1 = arg1->unk1C + temp_v0;
    temp_v1->unk36 = (s16) (s32) (temp_v1->unk38 * (f32) temp_v1->unk2E * D_809C42E0);
}
