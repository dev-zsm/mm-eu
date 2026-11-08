// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 THA_AllocTailAlign(s32, s32, M2C_UNK, s32);          /* extern */

void DynaPoly_AllocVtxList(struct PlayState *play, struct Vec3s **vtxList, s32 numVtx) {
    *vtxList = THA_AllocTailAlign((u8 *)play + 0x74, numVtx * 6, -2, play);
}
