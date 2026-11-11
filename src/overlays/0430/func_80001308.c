#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x222]; s16 unk222; s16 unk224; u8 pad226[0x4]; s16 unk22A; } S_arg5;
typedef struct { s16 unk0; u8 pad2[0x2]; s16 unk4; } S_arg4;

s32 func_80001308(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    s16 temp_v0;

    temp_v0 = (s16) arg5->unk222 >> 1;
    if (arg1 == 0xF) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk224);
        arg4->unk4 = (s16) (arg4->unk4 + (s16) temp_v0);
    }
    if (arg1 == 8) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk22A);
        arg4->unk4 = (s16) (arg4->unk4 + (s16) temp_v0);
    }
    return 0;
}
