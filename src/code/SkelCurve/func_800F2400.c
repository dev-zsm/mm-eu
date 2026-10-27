// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void *func_80100304(s32);                           /* extern */
s32 ZeldaArena_Malloc(s32);                             /* extern */

s32 SkelCurve_Init(s32 arg0, void *arg1, s32 arg2, M2C_UNK arg3) {
    void *temp_v0;

    temp_v0 = func_80100304(arg2);
    M2C_FIELD(arg1, u8 *, 0) = (u8) M2C_FIELD(temp_v0, u8 *, 4);
    M2C_FIELD(arg1, void **, 4) = func_80100304(M2C_FIELD(temp_v0, s32 *, 0));
    M2C_FIELD(arg1, s32 *, 0x1C) = ZeldaArena_Malloc(M2C_FIELD(arg1, u8 *, 0) * 0x12);
    M2C_FIELD(arg1, f32 *, 0x18) = 0.0f;
    return 1;
}
