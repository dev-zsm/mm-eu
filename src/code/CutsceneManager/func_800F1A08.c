// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Player_SetCsActionWithHaltedActors(s32, M2C_UNK, M2C_UNK);       /* extern */
s16 func_800F1B24(s16);                             /* extern */
M2C_UNK func_800F1D6C(s16);                         /* extern */
extern M2C_UNK D_801BE3E0;
extern s32 D_801BE3F0;

s16 func_800F1A08(s16 arg0) {
    s16 sp1E;
    s16 temp_v0;

    temp_v0 = func_800F1B24(arg0);
    sp1E = temp_v0;
    if (temp_v0 >= 0) {
        Player_SetCsActionWithHaltedActors(D_801BE3F0, 0, 7);
        if (M2C_FIELD(&D_801BE3E0, s16 *, 2) == 0) {
            func_800F1D6C(M2C_FIELD(&D_801BE3E0, s16 *, 0));
        }
        M2C_FIELD(&D_801BE3E0, s32 *, 0xC) = 1;
    }
    return sp1E;
}
