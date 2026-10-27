// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *func_80100304(s32);                           /* extern */
s32 ZeldaArena_Malloc(s32);                             /* extern */
M2C_UNK Animation_PlayLoop(void *, s32);                 /* extern */

void SkelAnime_Init(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *temp_v0;

    temp_v0 = func_80100304(arg2);
    M2C_FIELD(arg1, u8 *, 0) = (u8) (M2C_FIELD(temp_v0, u8 *, 4) + 1);
    M2C_FIELD(arg1, void **, 4) = func_80100304(M2C_FIELD(temp_v0, s32 *, 0));
    if (arg4 == 0) {
        M2C_FIELD(arg1, s32 *, 0x20) = ZeldaArena_Malloc(M2C_FIELD(arg1, u8 *, 0) * 6);
        M2C_FIELD(arg1, s32 *, 0x24) = ZeldaArena_Malloc(M2C_FIELD(arg1, u8 *, 0) * 6);
    } else {
        M2C_FIELD(arg1, s32 *, 0x20) = arg4;
        M2C_FIELD(arg1, s32 *, 0x24) = arg5;
    }
    if (arg3 != 0) {
        Animation_PlayLoop(arg1, arg3);
    }
}
