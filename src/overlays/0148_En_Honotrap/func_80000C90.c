// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

f32 func_800FEB44(s16, u8 *);                     /* extern */
f32 func_800FEB84(s16, u8 *);                     /* extern */
extern M2C_UNK D_80913CF8;

void EnHonotrap_SetupFlameDrop(EnHonotrap *this) {
    M2C_FIELD(this, s16 *, 0x220) = 0x28;
    M2C_FIELD(this, f32 *, 0x68) = 1.0f;
    M2C_FIELD(this, f32 *, 0x64) = (f32) (2.0f * func_800FEB84(M2C_FIELD(this, s16 *, 0x32), this));
    M2C_FIELD(this, f32 *, 0x6C) = (f32) (2.0f * func_800FEB44(M2C_FIELD(this, s16 *, 0x32), this));
    M2C_FIELD(this, M2C_UNK **, 0x144) = &D_80913CF8;
}
