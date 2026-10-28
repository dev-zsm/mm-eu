// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_809BF7C8;
extern f32 D_809C4848;

void func_800008A4(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x1670) = &D_809BF7C8;
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) D_809C4848;
}
