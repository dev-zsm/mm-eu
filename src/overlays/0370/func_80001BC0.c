#include "types.h"
#include "m2c_compat.h"

extern u8 D_801E7DF8;
extern M2C_UNK D_80A6D590;
extern M2C_UNK D_80A6D598;
extern M2C_UNK D_80A6D5A4;
extern M2C_UNK D_80A6D5AC;
extern M2C_UNK D_80A6D604;
extern M2C_UNK D_80A6D624;

M2C_UNK *func_80001BC0(u8 *arg0, M2C_UNK arg1) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16 *, 0x34E);
    if (temp_v0 & 0x2000) {
        if (M2C_FIELD(arg0, s32 *, 0x38C) == 0x23) {
            M2C_FIELD(arg0, s32 *, 0x390) = 1;
            return &D_80A6D604;
        }
        M2C_FIELD(arg0, s32 *, 0x390) = 2;
        return &D_80A6D604;
    }
    if (temp_v0 & 0x4000) {
        return &D_80A6D624;
    }
    if (temp_v0 & 0x80) {
        return &D_80A6D5A4;
    }
    if (!(temp_v0 & 0x40) && !(D_801E7DF8 & 0x10)) {
        return &D_80A6D598;
    }
    if ((temp_v0 & 0x1000) && !(D_801E7DF8 & 0x10)) {
        return &D_80A6D590;
    }
    return &D_80A6D5AC;
}
