// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0520.h"

M2C_UNK func_80B75B70(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_80B73FF8;

void func_80000D34(Actor *thisx) {
    if ((((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) == 1) || (M2C_FIELD(&D_801E6EF0, u8 *, 0xF0E) & 1)) {
        func_80B75B70(thisx, 1);
    } else {
        func_80B75B70(thisx, 2);
    }
    M2C_FIELD(thisx, s16 *, 0x31E) = 0;
    M2C_FIELD(thisx, M2C_UNK **, 0x188) = &D_80B73FF8;
}
