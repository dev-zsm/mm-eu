#include "types.h"
#include "m2c_compat.h"

typedef struct { s16 unk0; s16 unk2; s16 unk4; } S_arg4;
typedef struct { u8 pad0[0x2A0]; s16 unk2A0; s16 unk2A2; u8 pad2A4[0x2]; s16 unk2A6; s16 unk2A8; u8 pad2AA[0x6]; u16 unk2B0; } S_arg5;
typedef struct { u8 pad0[0x18840]; u32 unk18840; } S_arg0;

M2C_UNK func_8018132C(f32, f32, f32, M2C_UNK); /* extern */

s32 func_800010F4(S_arg0 *arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    if (arg1 == 8) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2A8);
        arg4->unk2 = (s16) (arg4->unk2 - arg5->unk2A6);
    } else if (arg1 == 0xF) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2A2);
        arg4->unk4 = (s16) (arg4->unk4 + arg5->unk2A0);
        if ((arg5->unk2B0 & 2) && (((u32) arg0->unk18840 % 3U) == 0)) {
            func_8018132C(4.0e+01f, 0.0f, 0.0f, 1);
        }
    }
    return 0;
}
