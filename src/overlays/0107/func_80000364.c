// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_8013796C(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000068;
extern M2C_UNK D_808CBCE0;

void func_80000364(u8 *arg0) {
    func_8013796C(arg0 + 0x144, &D_6000068, 0x40000000, arg0);
    M2C_FIELD(arg0, s16 *, 0x214) = 0xA;
    M2C_FIELD(arg0, M2C_UNK **, 0x20C) = &D_808CBCE0;
}
