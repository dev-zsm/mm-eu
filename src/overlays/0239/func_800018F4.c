#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801377D0(u8 *, M2C_UNK *, u8 *);   /* extern */
extern M2C_UNK D_6004638;
extern M2C_UNK D_809769C0;

void func_800018F4(u8 *arg0) {
    M2C_FIELD(arg0, u8 *, 0x461) = (u8) (M2C_FIELD(arg0, u8 *, 0x461) | 1);
    func_801377D0(arg0 + 0x144, &D_6004638, arg0);
    M2C_FIELD(arg0, u8 *, 0x340) = (u8) (M2C_FIELD(arg0, u8 *, 0x340) & 0xFFFB);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x92);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_809769C0;
    M2C_FIELD(arg0, f32 *, 0x154) = 20.0f;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
