// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

void Keyframe_ResetStandard(struct KFSkelAnime *kfSkelAnime) {
    M2C_FIELD(kfSkelAnime, s32 *, 0x18) = 0;
    M2C_FIELD(kfSkelAnime, s32 *, 0x1C) = 0;
    M2C_FIELD(kfSkelAnime, s32 *, 0x24) = 0;
    M2C_FIELD(kfSkelAnime, s32 *, 0x28) = 0;
    M2C_FIELD(kfSkelAnime, s32 *, 0x2C) = 0;
    M2C_FIELD(kfSkelAnime, f32 *, 0x20) = 0.0f;
}
