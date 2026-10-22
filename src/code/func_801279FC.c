// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(M2C_UNK *);                       /* extern */
M2C_UNK AnimatedMat_DrawOpa(s32, s32);                    /* extern */
extern s32 D_801EFA28;
extern M2C_UNK D_A001CD8;

void Player_DrawCouplesMask(s32 arg0, void *arg1) {
    D_801EFA28 = M2C_FIELD(arg1, s32 *, 0x23C) + 0x80000000;
    AnimatedMat_DrawOpa(arg0, func_80100304(&D_A001CD8));
}
