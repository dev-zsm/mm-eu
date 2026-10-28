// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
extern M2C_UNK D_80984534;
extern M2C_UNK D_809846C0;

s32 func_80000000(s32 arg0, M2C_UNK arg1, u8 *arg2, u8 *arg3) {
    s16 temp_v0;

    func_800FF30C(arg2, arg3);
    func_800FF30C(arg2 + 0xC, arg3 + 0xC);
    func_800FF30C(arg2 + 0x18, arg3 + 0x18);
    M2C_FIELD(arg2, s16 *, 0x40) = 0;
    temp_v0 = M2C_FIELD(arg3, s16 *, 0x24);
    if (temp_v0 < 0) {
        M2C_FIELD(arg2, s16 *, 0x42) = (s16) -temp_v0;
    } else {
        M2C_FIELD(arg2, s16 *, 0x42) = temp_v0;
    }
    if (M2C_FIELD(arg3, s16 *, 0x24) < 0) {
        M2C_FIELD(arg2, s16 *, 0x44) = 1;
        M2C_FIELD(arg2, s16 *, 0x46) = 2;
    } else {
        M2C_FIELD(arg2, s16 *, 0x44) = 3;
        M2C_FIELD(arg2, s16 *, 0x46) = 0xF;
    }
    M2C_FIELD(arg2, s16 *, 0x5C) = 0x32;
    M2C_FIELD(arg2, M2C_UNK **, 0x28) = &D_80984534;
    M2C_FIELD(arg2, M2C_UNK **, 0x24) = &D_809846C0;
    return 1;
}
