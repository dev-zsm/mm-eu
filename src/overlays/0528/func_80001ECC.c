#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0528.h"

s32 func_800B8254(u8 *, M2C_UNK);                 /* extern */
M2C_UNK func_800B8284(u8 *, M2C_UNK, f32, f32, s32); /* extern */
M2C_UNK func_80151DF4(M2C_UNK, M2C_UNK, u8 *);    /* extern */
M2C_UNK func_80B7D068(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80B7D448;

void func_80001ECC(u8 *arg0, M2C_UNK arg1) {
    func_80B7D068(arg0, arg1);
    if (func_800B8254(arg0, arg1) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x2D4) == 2) {
            func_80151DF4(arg1, 0x12AD, arg0);
        } else {
            func_80151DF4(arg1, 0x12B0, arg0);
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x2F8) = &D_80B7D448;
        return;
    }
    func_800B8284(arg0, arg1, 1.0e+03f, 1.0e+03f, -1);
}
