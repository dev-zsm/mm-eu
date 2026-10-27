// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Gfx_TexScroll(s32, s32, s32, u8, s32);      /* extern */
extern s32 D_801ED320;

void AnimatedMat_TexScroll(s32 *arg0, void *arg1) {
    Gfx_TexScroll(*arg0, M2C_FIELD(arg1, s8 *, 0) * D_801ED320, -(M2C_FIELD(arg1, s8 *, 1) * D_801ED320), M2C_FIELD(arg1, u8 *, 2), (s32) M2C_FIELD(arg1, u8 *, 3));
}
