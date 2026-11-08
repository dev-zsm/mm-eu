// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0643.h"

M2C_UNK func_800C60A4(s32, s32, s32);               /* extern */
s32 func_800CAD00(u8 *);                          /* extern */
M2C_UNK func_80BFFB60(u8 *, s32);                 /* extern */
extern M2C_UNK D_80BFFD34;

void ObjDanpeilift_Teleport(ObjDanpeilift *this, PlayState *play) {
    if (func_800CAD00(this) == 0) {
        func_80BFFB60(this, M2C_FIELD(this, s32 *, 0x168));
        func_800C60A4(play, (u8 *)play + 0x880, M2C_FIELD(this, s32 *, 0x144));
        M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_80BFFD34;
    }
}
