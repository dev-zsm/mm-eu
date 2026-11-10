#include "types.h"
#include "m2c_compat.h"

s32 func_80124578(u8 *);                          /* extern */
s32 func_80124708(u8 *);                          /* extern */
M2C_UNK func_8082EF6C(s32, u8 *, M2C_UNK);        /* extern */

void func_80000210(s32 arg0, u8 *arg1) {
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg1, u8 **, 0x34C);
    if (temp_v1 != NULL) {
        if (func_80124578(arg1) == 0) {
            M2C_FIELD(arg1, s32 *, 0x124) = 0;
            M2C_FIELD(arg1, u8 **, 0x34C) = NULL;
            M2C_FIELD(arg1, s32 *, 0x388) = 0;
            M2C_FIELD(temp_v1, s32 *, 0x120) = 0;
            M2C_FIELD(arg1, s32 *, 0xA6C) = (s32) (M2C_FIELD(arg1, s32 *, 0xA6C) & ~0x800);
        }
    }
    if (func_80124708(arg1) >= 0) {
        func_8082EF6C(arg0, arg1, 0);
        M2C_FIELD(arg1, u8 *, 0x148) = 0xFE;
    }
}
