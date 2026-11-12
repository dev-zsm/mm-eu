#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0246.h"

M2C_UNK func_800FFAD8(s32, M2C_UNK, M2C_UNK, M2C_UNK, f32); /* extern */
s32 func_8013DA3C(u8 *, s16, M2C_UNK *);            /* extern */
s32 func_8013DB18(u8 *, M2C_UNK *, s16);          /* extern */
M2C_UNK func_809834D0(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80983A8C;

void func_800004C0(u8 *arg0, M2C_UNK arg1) {
    s16 sp36;
    s32 pad2[2];
    M2C_UNK sp28;

    func_800FFAD8(arg0 + 0x70, 0x3F800000, 0x3ECCCCCD, 0x447A0000, 0.0f);
    sp36 = (s16) (s32) (M2C_FIELD(arg0, f32 *, 0x70) * 400.0f);
    if ((func_8013DA3C(M2C_FIELD(arg0, u8 **, 0x1DC), M2C_FIELD(arg0, s16 *, 0x1E0), &sp28) != 0) && (func_8013DB18(arg0, &sp28, sp36) != 0)) {
        M2C_FIELD(arg0, s16 *, 0x1E0) = (s16) (M2C_FIELD(arg0, s16 *, 0x1E0) + 1);
        if (M2C_FIELD(arg0, s16 *, 0x1E0) >= (s32) *M2C_FIELD(arg0, u8 **, 0x1DC)) {
            M2C_FIELD(arg0, s16 *, 0x1E0) = 0;
        }
    }
    if (M2C_FIELD(arg0, f32 *, 0x8C) > 60.0f) {
        func_809834D0(arg0 + 0x148, 1);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_80983A8C;
        M2C_FIELD(arg0, f32 *, 0x74) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
}
