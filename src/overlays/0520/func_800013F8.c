// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B75B70(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B746B8;

void func_800013F8(u8 *arg0) {
    if ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 1) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0E) & 1)) {
        func_80B75B70(arg0, 1);
    } else {
        func_80B75B70(arg0, 2);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B746B8;
}
