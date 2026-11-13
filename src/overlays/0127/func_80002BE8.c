#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0127.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
s32 func_801244EC(s32);                             /* extern */
M2C_UNK func_808F4DE8(s32, u8 *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_808F5218;

void func_80002BE8(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    if (M2C_FIELD(arg0, s32 *, 0x4B0) == 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_808F5218;
    }
    if (((func_801244EC(arg1) == 8) && (M2C_FIELD(&D_801E6EF0, u8 *, 0xF37) & 0x40)) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF30) & 8)) {
        if (M2C_FIELD(&D_801E6EF0, s32 *, 0x18) != 3) {
            func_808F4DE8(arg1, arg0, 2, arg0 + 0x48C);
        } else {
            func_808F4DE8(arg1, arg0, 6, arg0 + 0x48C);
        }
    }
    if (M2C_FIELD(arg0, s32 *, 0x4A8) == 2) {
        if (M2C_FIELD(arg0, s32 *, 0x4B0) == 2) {
            func_800B8C4C(arg0, 0x6855);
        } else {
            func_800B8C4C(arg0, 0x687C);
        }
        M2C_FIELD(arg0, s32 *, 0x4A8) = 3;
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0x4A8) < 3) {
        M2C_FIELD(arg0, s32 *, 0x4A8) = (s32) (M2C_FIELD(arg0, s32 *, 0x4A8) + 1);
    }
}
