#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x2]; s16 unk2; } S_arg4;
typedef struct { u8 pad0[0x258]; s16 unk258; s16 unk25A; s16 unk25C; } S_arg5;

s32 func_8000105C(s32 arg0, s32 arg1, M2C_UNK arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    S_arg5 *this = arg5;
    if (arg1 == 1) {
        arg4->unk2 = (s16) (arg4->unk2 + arg5->unk25C);
    }
    if (arg1 == 3) {
        arg4->unk2 = (s16) (arg4->unk2 + arg5->unk258);
    }
    if (arg1 == 4) {
        arg4->unk2 = (s16) (arg4->unk2 + arg5->unk25A);
    }
    return 0;
}
