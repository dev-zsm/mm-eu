#include "types.h"
#include "m2c_compat.h"

typedef struct { s16 unk0; u8 pad2[0x2]; s16 unk4; } S_arg4;
typedef struct { u8 pad0[0x2F0]; s16 unk2F0; s16 unk2F2; u8 pad2F4[0x4]; s16 unk2F8; u8 pad2FA[0x26]; u16 unk320; s16 unk322; } S_arg5;

s32 func_800011A0(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    S_arg5 *this = arg5;
    if (arg1 == 0xC) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2F2);
        if ((arg5->unk320 & 0x10) && (arg5->unk322 == 0)) {
            arg4->unk4 = (s16) (arg4->unk4 + arg5->unk2F0);
        }
    }
    if (arg1 == 0xB) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2F8);
    }
    return 0;
}
