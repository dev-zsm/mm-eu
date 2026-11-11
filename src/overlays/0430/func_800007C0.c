#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0430.h"

s32 func_800B877C(u8 *, s32);                             /* extern */
M2C_UNK func_800B87A0(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
extern M2C_UNK D_80AC5148;

void func_800007C0(u8 *arg0, s32 arg1) {
    if (func_800B877C(arg0, arg1) != 0) {
        M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x1D8), s16 *, 0x18) = 0;
        M2C_FIELD(arg0, M2C_UNK **, 0x1D4) = &D_80AC5148;
        return;
    }
    func_800B87A0(arg0, arg1, 0x95, 0x44FA0000, 1000.0f);
}
