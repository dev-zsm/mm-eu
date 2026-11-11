#include "types.h"
#include "m2c_compat.h"

s32 func_800B5C34(u8 *, M2C_UNK);                 /* extern */
extern M2C_UNK D_80AF5D78;
extern M2C_UNK D_80AF5EDC;
extern M2C_UNK D_80AF6588;

void func_80001C88(u8 *arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, s8 *, 0x186E0) == 1) {
        M2C_FIELD(arg0, s16 *, 0x290) = 0;
        M2C_FIELD(arg0, s16 *, 0x282) = (s16) M2C_FIELD(arg0, s8 *, 0x38);
        if ((func_800B5C34(arg1, 2) != 0) && (func_800B5C34(arg1, 3) != 0) && (func_800B5C34(arg1, 4) != 0) && (func_800B5C34(arg1, 5) != 0)) {
            M2C_FIELD(arg0, u8 *, 0x28A) = 0xFF;
            M2C_FIELD(arg0, u16 *, 0x26C) = (u16) (M2C_FIELD(arg0, u16 *, 0x26C) & 0xFEFF);
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
            M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80AF6588;
            M2C_FIELD(arg0, s16 *, 0x26E) = 0x14F9;
            M2C_FIELD(arg0, M2C_UNK **, 0x218) = &D_80AF5D78;
            return;
        }
        M2C_FIELD(arg0, M2C_UNK **, 0x218) = &D_80AF5EDC;
    }
}
