#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80136E1C(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_80A9FFCC(u8 *);                      /* extern */
M2C_UNK func_80AA0584(u8 *, s32);                 /* extern */
extern M2C_UNK D_6002848;
extern M2C_UNK D_6002A08;
extern M2C_UNK D_800B3F30;
extern u8 D_801E7DFF;
extern M2C_UNK D_80AA0B20;
extern s32 D_80AA0B4C;

void func_80000000(u8 *arg0, s32 arg1) {
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136E1C(arg1, arg0 + 0x144, &D_6002848, &D_6002A08, arg0 + 0x188, arg0 + 0x1CA, 0xB);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x1F) = 1;
    func_800E1134(arg1, arg0 + 0x244, arg0, &D_80AA0B20);
    func_800B6564(arg0, 0x3C75C28F);
    func_800FF30C(arg0 + 0x228, arg0 + 0x24);
    M2C_FIELD(arg0, s16 *, 0x21E) = (s16) D_80AA0B4C;
    D_80AA0B4C += 1;
    if (!(D_801E7DFF & 0x20)) {
        func_80A9FFCC(arg0);
        return;
    }
    func_80AA0584(arg0, arg1);
}
