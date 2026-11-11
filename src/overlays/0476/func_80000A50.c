#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0476.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
s32 func_80137070(s32);                             /* extern */
M2C_UNK func_80B11890(u8 *);                      /* extern */
extern f32 D_80B14494;

void func_80000A50(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;

    if (func_80137070(arg0 + 0x144) != 0) {
        M2C_FIELD(arg0, u8 *, 0x197) = 0xFF;
        M2C_FIELD(arg0, s16 *, 0x190) = func_800FF250(0x2BC, 0x12C);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        func_80B11890(arg0);
    } else {
        temp_f0 = M2C_FIELD(arg0, f32 *, 0x15C);
        if (temp_f0 > 10.0f) {
            M2C_FIELD(arg0, s8 *, 0x197) = (s8) (u32) ((temp_f0 - 10.0f) * D_80B14494 * 255.0f);
        }
    }
    if ((M2C_FIELD(arg0, f32 *, 0x160) < 0.5f) && (M2C_FIELD(arg0, f32 *, 0x98) < 280.0f)) {
        func_800B8C4C(arg0, 0x3873);
        M2C_FIELD(arg0, f32 *, 0x160) = 1.0f;
    }
}
