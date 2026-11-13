#include "types.h"
#include "m2c_compat.h"

typedef struct { s16 unk0; u8 pad2[0x2]; s16 unk4; } S_arg4;
typedef struct { u8 pad0[0x288]; s16 unk288; s16 unk28A; u8 pad28C[0xA]; s16 unk296; } S_arg5;

s32 func_80000DA4(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    S_arg5 *this = arg5;
    if (arg1 == 8) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk296);
    }
    if (arg1 == 0x11) {
        arg4->unk0 = (s16) (arg4->unk0 + arg5->unk28A);
        arg4->unk4 = (s16) (arg4->unk4 + arg5->unk288);
    }
    if ((arg1 == 0xF) || (arg1 == 0x13) || (arg1 == 0x14)) {
        *arg2 = 0;
    }
    return 0;
}
