// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK SkelAnime_InterpFrameTable(u8, s32, s32, s32, f32);      /* extern */
extern s32 D_801ED334;

void AnimTask_Interp(s32 arg0, void *arg1) {
    s32 temp_a1;

    if (!(M2C_FIELD(arg1, u8 *, 0) & D_801ED334)) {
        temp_a1 = M2C_FIELD(arg1, s32 *, 4);
        SkelAnime_InterpFrameTable(M2C_FIELD(arg1, u8 *, 1), temp_a1, temp_a1, M2C_FIELD(arg1, s32 *, 8), M2C_FIELD(arg1, f32 *, 0xC));
    }
}
