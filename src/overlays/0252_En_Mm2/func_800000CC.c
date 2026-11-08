// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0252.h"

s32 func_800B70A4(u8 *, M2C_UNK, s32);            /* extern */
s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
extern M2C_UNK D_80986DC0;

void EnMm2_WaitForRead(EnMm2 *this, PlayState *play) {
    if (func_800B8254(this, play) != 0) {
        func_80151DF4(play, 0x277B, this);
        M2C_FIELD(this, M2C_UNK **, 0x188) = &D_80986DC0;
        return;
    }
    if ((M2C_FIELD(this, f32 *, 0x98) < 60.0f) && (func_800B70A4(this, 0x3000, play) != 0)) {
        func_800B8398(this, play, 0x42DC0000);
    }
}
