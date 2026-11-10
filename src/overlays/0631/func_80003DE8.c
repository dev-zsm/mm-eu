#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x2B0]; s32 unk2B0; u8 pad2B4[0x68]; s16 unk31C; s16 unk31E; s16 unk320; } S_arg5;
typedef struct { s16 unk0; s16 unk2; s16 unk4; } S_arg4;

s32 func_80003DE8(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    s32 temp_v0;

    temp_v0 = arg5->unk2B0;
    if (arg1 != temp_v0) {
        *arg2 = 0;
    } else if (arg1 != temp_v0) {
        *arg2 = 0;
    } else if ((arg1 == 2) || (arg1 == 3) || (arg1 == 4) || (arg1 == 5) || (arg1 == 6) || (arg1 == 7) || (arg1 == 8) || (arg1 == 9) || (arg1 == 0xA) || (arg1 == 0xC) || (arg1 == 0xD) || (arg1 == 0xF) || (arg1 == 0x10) || (arg1 == 0x11) || (arg1 == 0x12) || (arg1 == 0x13) || (arg1 == 0x14)) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk31C);
        arg4->unk2 = (s16) (arg4->unk2 + arg5->unk31E);
        arg4->unk4 = (s16) (arg4->unk4 + arg5->unk320);
    }
    return 0;
}
