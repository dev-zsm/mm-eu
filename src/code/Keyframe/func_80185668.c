// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 func_80100304(s32);                             /* extern */
M2C_UNK FrameCtrl_Init(void *);                      /* extern */
M2C_UNK Keyframe_ResetStandard(void *);                      /* extern */

void Keyframe_InitStandard(struct KFSkelAnime *kfSkelAnime, struct KeyFrameSkeleton *skeleton, struct KeyFrameAnimation *animation, struct Vec3s *jointTable, struct Vec3s *morphTable) {
    Keyframe_ResetStandard(kfSkelAnime);
    FrameCtrl_Init(kfSkelAnime);
    M2C_FIELD(kfSkelAnime, s32 *, 0x18) = func_80100304(skeleton);
    M2C_FIELD(kfSkelAnime, s32 *, 0x1C) = func_80100304(animation);
    M2C_FIELD(kfSkelAnime, s32 *, 0x24) = jointTable;
    M2C_FIELD(kfSkelAnime, s32 *, 0x28) = morphTable;
}
