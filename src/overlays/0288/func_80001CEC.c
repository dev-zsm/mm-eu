#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
f32 func_8017A844(f32);                         /* extern */
extern M2C_UNK D_6007488;
extern M2C_UNK D_809D4F74;

void func_80001CEC(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x170) = &D_809D4F74;
    func_80137934(arg0 + 0x3C8, &D_6007488, 0xC1200000, arg0);
    M2C_FIELD(arg0, s16 *, 0x162) = (s16) (s32) (func_8017A844(25.0f) + 25.0f);
    func_800B8C4C(arg0, 0x3860);
}
