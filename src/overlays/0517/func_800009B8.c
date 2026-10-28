// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, M2C_UNK *, u8 *);   /* extern */
extern M2C_UNK D_801C9EE0;
extern M2C_UNK D_80B6ACC8;

void func_800009B8(u8 *arg0) {
    func_800FF30C(arg0 + 0x2F8, &D_801C9EE0, arg0);
    func_800FF30C(arg0 + 0x304, &D_801C9EE0, arg0);
    M2C_FIELD(arg0, s8 *, 0x2D8) = 1;
    M2C_FIELD(arg0, s16 *, 0x2B0) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0x2AC) = &D_80B6ACC8;
}
