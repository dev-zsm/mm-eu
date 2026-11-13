#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0127.h"

M2C_UNK func_800FFAD8(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_8013DA3C(u8 *, s16, M2C_UNK *);            /* extern */
s32 func_8013DB18(u8 *, M2C_UNK *, s16);          /* extern */

void func_800005E0(u8 *arg0, M2C_UNK arg1) {
    s16 sp36;
    s32 pad2[2];
    M2C_UNK sp28;

    func_800FFAD8(arg0 + 0x70, 0x3F800000, 0x3ECCCCCD, 0x447A0000, 0.0f);
    sp36 = (s16) (s32) (M2C_FIELD(arg0, f32 *, 0x70) * 400.0f);
    if ((func_8013DA3C(M2C_FIELD(arg0, u8 **, 0x240), M2C_FIELD(arg0, s16 *, 0x244), &sp28) != 0) && (func_8013DB18(arg0, &sp28, sp36) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x244) = (s16) (M2C_FIELD(arg0, s16 *, 0x244) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x244) >= (s32) *M2C_FIELD(arg0, u8 **, 0x240)) {
            M2C_FIELD(arg0, s16 *, 0x244) = 0;
        }
    }
}
