#include "types.h"
#include "m2c_compat.h"

f32 func_8008704C();                                /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, s32);         /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_6017568;
extern M2C_UNK D_809B7644;
extern f32 D_809BCD24;

void func_80002328(u8 *arg0, M2C_UNK arg1) {
    func_80137934(arg0 + 0x164, &D_6017568, M2C_FIELD(arg0, s32 *, 0x158));
    M2C_FIELD(arg0, M2C_UNK **, 0x464) = &D_809B7644;
    M2C_FIELD(arg0, s16 *, 0x14E) = (s16) (s32) (func_8017A844(1.0e+02f) + 50.0f);
    M2C_FIELD(arg0, f32 *, 0x1B0) = (f32) D_809BCD24;
    if (func_8008704C() < 0.5f) {
        M2C_FIELD(arg0, f32 *, 0x1B0) = (f32) (M2C_FIELD(arg0, f32 *, 0x1B0) * -1.0f);
    }
    M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
}
