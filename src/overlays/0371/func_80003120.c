#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0371.h"

M2C_UNK func_80A733D4();                            /* extern */
M2C_UNK func_80A733F4();                            /* extern */

void func_80003120(u8 *arg0) {
    if (M2C_FIELD(arg0, f32 *, 0x164) >= 40.0f) {
        func_80A733F4();
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x164) >= 35.0f) {
        M2C_FIELD(arg0, s16 *, 0x3D8) = 1;
        return;
    }
    if (M2C_FIELD(arg0, f32 *, 0x164) >= 10.0f) {
        func_80A733D4();
    }
}
