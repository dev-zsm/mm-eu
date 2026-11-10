#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x194]; s16 unk194; u8 pad196[0x24E]; s32 unk3E4; } S_arg5;
typedef struct { u8 pad0[0x4]; s16 unk4; } S_arg4;

s32 func_8000297C(s32 arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    if ((arg1 == 0xA) || (arg1 == 0xB)) {
        arg5->unk3E4 = (s32) *arg2;
        *arg2 = 0;
    } else if (arg1 == 0x10) {
        *arg2 = 0;
    } else if (arg1 == 8) {
        arg4->unk4 = (s16) (arg4->unk4 + arg5->unk194);
    }
    return 0;
}
