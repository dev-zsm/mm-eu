#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80AA2A5C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80AA4A04(u8 *);                      /* extern */
extern M2C_UNK D_80AA3290;
extern f32 D_80AA4FA4;
extern f32 D_80AA4FA8;

void func_80000804(u8 *arg0) {
    if ((M2C_FIELD(arg0, s16 *, 0x336) != 2) && (M2C_FIELD(arg0, s16 *, 0x336) != 3)) {
        if (M2C_FIELD(arg0, s16 *, 0x332) != 2) {
            func_80AA2A5C(arg0, 9);
            M2C_FIELD(arg0, f32 *, 0x70) = (f32) D_80AA4FA4;
        } else {
            func_80AA2A5C(arg0, 0xF);
            M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        }
    } else {
        func_80AA2A5C(arg0, 1);
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    }
    M2C_FIELD(arg0, f32 *, 0x74) = (f32) D_80AA4FA8;
    M2C_FIELD(arg0, s16 *, 0x33C) = 0;
    func_80AA4A04(arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AA3290;
}
