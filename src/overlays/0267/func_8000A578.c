#include "types.h"
#include "m2c_compat.h"

typedef struct { s16 unk0; u8 pad2[0x2]; s16 unk4; } S_arg4;
typedef struct { u8 pad0[0x184]; s16 unk184; u8 pad186[0x2A2]; s16 unk428; } S_arg5;

s32 func_8000A578(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    S_arg5 *this = arg5;
    if (arg1 == 0xF) {
        arg4->unk0 = (s16) (s32) ((f32) arg4->unk0 + (f32) arg5->unk184);
    }
    if (arg1 == 0x12) {
        arg4->unk4 = (s16) (arg4->unk4 + arg5->unk428);
    } else if (arg1 == 0x13) {
        arg4->unk4 = (s16) (arg4->unk4 - arg5->unk428);
    }
    if ((arg1 != 0x12) && (arg1 != 0x13)) {
        *arg2 = 0;
    }
    return 0;
}
