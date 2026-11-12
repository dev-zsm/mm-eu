#include "types.h"
#include "m2c_compat.h"

typedef struct { s16 unk0; u8 pad2[0x2]; s16 unk4; } S_arg4;
typedef struct { u8 pad0[0x2DE]; s16 unk2DE; s16 unk2E0; u8 pad2E2[0x2]; s16 unk2E4; } S_arg5;

s32 func_80001438(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    S_arg5 *this = arg5;
    if (arg1 == 8) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2E4);
    }
    if (arg1 == 0xF) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2DE);
        arg4->unk4 = (s16) (arg4->unk4 + arg5->unk2E0);
    }
    return 0;
}
