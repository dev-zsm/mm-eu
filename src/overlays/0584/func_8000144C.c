#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0584.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80BC1B48(u8 *, u8 *);              /* extern */
M2C_UNK func_80BC1DEC(u8 *, M2C_UNK, M2C_UNK);    /* extern */
extern M2C_UNK D_80BC23D4;

void func_8000144C(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    s16 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2CE);
    if (temp_v0 < 0xF5) {
        M2C_FIELD(arg0, s16 *, 0x2CE) = (s16) (temp_v0 + 0xA);
    } else {
        M2C_FIELD(arg0, s16 *, 0x2CE) = 0xFF;
    }
    if (M2C_FIELD(arg0, f32 *, 0x8C) < 54.0f) {
        func_800B8C4C(arg0, 0x2808);
        func_80BC1B48(arg0, arg0 + 0x2D0);
        func_80BC1DEC(arg0, 1, 2);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        M2C_FIELD(arg0, M2C_UNK **, 0x618) = &D_80BC23D4;
        M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x8C) < 80.0f) {
        func_800FFBF8(arg0 + 0x68, 0x40000000, 0x3ECCCCCD, 0x3F19999A);
    }
}
