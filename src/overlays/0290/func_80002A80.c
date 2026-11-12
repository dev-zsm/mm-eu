#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_60407D0;
extern M2C_UNK D_809DC1BC;

void func_80002A80(u8 *arg0, M2C_UNK arg1, s16 arg2) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809DC1BC;
    func_80137934(arg0 + 0x190, &D_60407D0, 0xC1200000, arg0);
    if (arg2 != 0) {
        M2C_FIELD(arg0, s16 *, 0x150) = arg2;
    } else {
        M2C_FIELD(arg0, s16 *, 0x150) = (s16) (s32) func_8017A844(3.0e+01f);
    }
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
}
