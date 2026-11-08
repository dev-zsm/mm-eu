// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

s32 THA_AllocTailAlign(s32, s32, M2C_UNK, s32);          /* extern */

void DynaPoly_AllocWaterBoxList(struct PlayState *play, struct DynaWaterBoxList *waterBoxList, s32 numWaterBoxes) {
    M2C_FIELD(waterBoxList, s32 *, 4) = THA_AllocTailAlign((u8 *)play + 0x74, numWaterBoxes * 0x10, -2, play);
}
