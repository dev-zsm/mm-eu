// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0086.h"

M2C_UNK func_800B8D6C(u8 *, M2C_UNK);             /* extern */
s32 func_800FEC70(s32, M2C_UNK, M2C_UNK);           /* extern */
M2C_UNK func_8016AAF8(s32, s16, s16);               /* extern */
M2C_UNK func_808A7324(u8 *, s32);                 /* extern */

void ObjWturn_InversionCs(ObjWturn *this, PlayState *play) {
    if (func_800FEC70((u8 *)this + 0xC0, -0x8000, 0x200) != 0) {
        func_808A7324(this, play);
    }
    func_800B8D6C(this, 0x2098);
    func_8016AAF8(play, M2C_FIELD(this, s16 *, 0x148), M2C_FIELD(this, s16 *, 0xC0));
}
