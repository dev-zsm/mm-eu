// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0276.h"

s32 func_800FEE3C(u8 *, s32, M2C_UNK, u8 *);    /* extern */
extern M2C_UNK D_809AEABC;

void BgIcicle_Regrow(BgIcicle *this, PlayState *play) {
    if (func_800FEE3C((u8 *)this + 0x28, M2C_FIELD(this, s32 *, 0xC), 0x3F800000, this) != 0) {
        M2C_FIELD(this, M2C_UNK **, 0x15C) = &D_809AEABC;
        M2C_FIELD(this, f32 *, 0x68) = 0.0f;
    }
}
