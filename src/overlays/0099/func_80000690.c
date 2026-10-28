// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_600326C;
extern M2C_UNK D_808BCFB8;
extern M2C_UNK D_808BD12C;

void func_80000690(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_600326C, 0xC0400000, arg0);
    if (&D_808BD12C == M2C_FIELD(arg0, M2C_UNK **, 0x188)) {
        M2C_FIELD(arg0, s16 *, 0x190) = 0x1002;
    } else {
        M2C_FIELD(arg0, s16 *, 0x190) = 1;
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BCFB8;
}
