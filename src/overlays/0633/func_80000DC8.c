// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000604;
extern M2C_UNK D_80BF6330;

void func_80000DC8(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6000604, 0xC0800000, arg0);
    M2C_FIELD(arg0, s16 *, 0x18E) = 0x3C;
    M2C_FIELD(arg0, u8 *, 0x281) = (u8) (M2C_FIELD(arg0, u8 *, 0x281) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BF6330;
}
