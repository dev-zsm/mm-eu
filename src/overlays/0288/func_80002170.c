#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, f32, u8 *); /* extern */
extern M2C_UNK D_60006A4;
extern M2C_UNK D_809D53E8;

void func_80002170(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x170) = &D_809D53E8;
    func_80137828(arg0 + 0x3C8, &D_60006A4, 0, arg0);
    M2C_FIELD(arg0, f32 *, 0x4FC) = (f32) func_80134AE8(&D_60006A4);
    func_800B8C4C(arg0, 0x3837);
}
