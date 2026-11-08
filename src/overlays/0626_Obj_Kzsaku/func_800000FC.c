// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0626.h"

s32 func_800B5B20(M2C_UNK, s32, M2C_UNK);           /* extern */
M2C_UNK func_80BED95C(u8 *);                      /* extern */

void ObjKzsaku_Idle(ObjKzsaku *this, PlayState *play) {
    if (func_800B5B20(play, M2C_FIELD(this, s32 *, 0x164), play) != 0) {
        func_80BED95C(this);
    }
}
