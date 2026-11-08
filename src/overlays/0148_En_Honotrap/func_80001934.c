// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0148.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
f32 func_800FEB84(s16);                             /* extern */

void EnHonotrap_UpdateFlame(Actor *thisx, PlayState *play) {
    s16 temp_v0;

    temp_v0 = M2C_FIELD(thisx, s16 *, 0x220);
    if (temp_v0 > 0) {
        M2C_FIELD(thisx, s16 *, 0x220) = (s16) (temp_v0 - 1);
    }
    M2C_FIELD(thisx, s8 *, 0x2C0) = 0;
    M2C_FIELD(thisx, s16 *, 0x238) = (s16) (M2C_FIELD(thisx, s16 *, 0x238) + 0x640);
    if (M2C_FIELD(thisx, s16 *, 0x1C) != 4) {
        M2C_FIELD(thisx, f32 *, 0xC4) = (f32) ((func_800FEB84(M2C_FIELD(thisx, s16 *, 0x238)) * 1000.0f) + 600.0f);
    }
    func_800B64E0(thisx, 0x40A00000);
    func_800B8C4C(thisx, 0x205B);
    M2C_FIELD(thisx, M2C_UNK (**)(u8 *, s32), 0x144)(thisx, play);
    M2C_FIELD(thisx, s16 *, 0x23A) = (s16) (M2C_FIELD(thisx, s16 *, 0x23A) - 0x14);
    M2C_FIELD(thisx, s16 *, 0x23A) = (s16) (M2C_FIELD(thisx, s16 *, 0x23A) & 0x1FF);
}
