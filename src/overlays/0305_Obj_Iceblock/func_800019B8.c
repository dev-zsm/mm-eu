// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0305.h"

M2C_UNK func_800C60A4(s32, s32, s32, u8 *);       /* extern */

void func_800019B8(ObjIceblock *this, PlayState *play) {
    if (!(M2C_FIELD(this, s32 *, 0x1B0) & 0x10) && !(M2C_FIELD(this, u8 *, 0x16E) & 2)) {
        func_800C60A4(play, (u8 *)play + 0x880, M2C_FIELD(this, s32 *, 0x144), this);
        M2C_FIELD(this, s32 *, 0x1B0) = (s32) (M2C_FIELD(this, s32 *, 0x1B0) | 0x10);
    }
}
