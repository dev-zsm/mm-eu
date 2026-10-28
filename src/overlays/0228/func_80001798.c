// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
s32 func_800FEE3C(u8 *, M2C_UNK, M2C_UNK);        /* extern */
M2C_UNK func_80968AFC(u8 *);                      /* extern */
M2C_UNK func_80968BDC(u8 *);                      /* extern */

void func_80001798(u8 *arg0) {
    s32 temp_v0;

    M2C_FIELD(arg0, s16 *, 0x14A) = (s16) (M2C_FIELD(arg0, s16 *, 0x14A) + 1);
    if ((((s16) M2C_FIELD(arg0, s16 *, 0x14A) % 25) == 0) && ((s32) M2C_FIELD(arg0, u8 *, 0xD0) >= 0x1A)) {
        func_80968AFC(arg0);
    }
    func_800B8D94(arg0, 0x2144);
    if (func_800FEE3C(arg0 + 0x5C, 0x3A83126F, 0x3A449BA6) != 0) {
        temp_v0 = M2C_FIELD(arg0, u8 *, 0xD0) - 4;
        if (temp_v0 <= 0) {
            M2C_FIELD(arg0, u8 *, 0xD0) = 0U;
            func_80968BDC(arg0);
        } else {
            M2C_FIELD(arg0, u8 *, 0xD0) = (u8) temp_v0;
        }
    }
    func_800FEE3C(arg0 + 0x58, 0x3E800000, 0x3A83126F);
    M2C_FIELD(arg0, f32 *, 0x60) = (f32) M2C_FIELD(arg0, f32 *, 0x58);
}
