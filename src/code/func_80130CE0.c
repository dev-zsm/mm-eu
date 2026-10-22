// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Gfx_TwoTexScroll(s32, M2C_UNK, s32, s32, s32, s32, s32, s32, s32, s32, s32); /* extern */
extern s32 D_801ED320;

void AnimatedMat_TwoLayerTexScroll(s32 *arg0, void *arg1) {
    Gfx_TwoTexScroll(*arg0, 0, M2C_FIELD(arg1, s8 *, 0) * D_801ED320, -(M2C_FIELD(arg1, s8 *, 1) * D_801ED320), (s32) M2C_FIELD(arg1, u8 *, 2), (s32) M2C_FIELD(arg1, u8 *, 3), 1, M2C_FIELD(arg1, s8 *, 4) * D_801ED320, -(M2C_FIELD(arg1, s8 *, 5) * D_801ED320), (s32) M2C_FIELD(arg1, u8 *, 6), (s32) M2C_FIELD(arg1, u8 *, 7));
}
