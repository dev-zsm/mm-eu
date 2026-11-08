// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0058.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFCBC(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80863E80(u8 *, s32);                 /* extern */

void EnGirlA_Update2(EnGirlA *this, PlayState *play) {
    func_800B6564(this, 0x3E800000);
    M2C_FIELD(this, f32 *, 0xC4) = 24.0f;
    M2C_FIELD(this, f32 *, 0xCC) = 4.0f;
    func_80863E80(this, play);
    M2C_FIELD(this, M2C_UNK (**)(u8 *, s32), 0x188)(this, play);
    func_800B64E0(this, 0x40A00000);
    M2C_FIELD(this, s16 *, 0xBC) = 0;
    if (M2C_FIELD(this, s16 *, 0x1AC) != 0) {
        M2C_FIELD(this, s16 *, 0x1B0) = (s16) (M2C_FIELD(this, s16 *, 0x1B0) + 0x1F4);
        return;
    }
    func_800FFCBC((u8 *)this + 0x1B0, 0, 0xA, 0x7D0, 0);
}
