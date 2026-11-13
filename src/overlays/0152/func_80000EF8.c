#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0152.h"

s32 func_8012FA08(s32, s8, s32);                    /* extern */
M2C_UNK func_8091A478(u8 *);                      /* extern */
M2C_UNK func_8091AC10(u8 *);                      /* extern */
extern M2C_UNK D_8091AF04;
extern M2C_UNK D_8091B0BC;

void func_80000EF8(u8 *arg0, s32 arg1) {
    s16 pad_h;
    s32 sp20;

    if (func_8012FA08(arg1 + 0x17D88, M2C_FIELD(arg0, s8 *, 0x195), arg1) != 0) {
        sp20 = M2C_FIELD(arg0, s16 *, 0x1C) & 3;
        if (M2C_FIELD(arg0, u8 *, 0x197) != 0) {
            func_8091AC10(arg0);
        } else {
            func_8091A478(arg0);
        }
        if (sp20 == 0) {
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_8091AF04;
        } else {
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_8091B0BC;
        }
        M2C_FIELD(arg0, s8 *, 0x1E) = (s8) M2C_FIELD(arg0, s8 *, 0x195);
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~0x10);
    }
}
