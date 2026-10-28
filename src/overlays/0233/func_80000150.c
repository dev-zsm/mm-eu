// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_80971810();                            /* extern */
extern M2C_UNK D_8097191C;

void func_80000150(u8 *arg0) {
    if ((M2C_FIELD(arg0, s32 *, 4) & 0x2000) == 0x2000) {
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8097191C;
        goto block_4;
    }
    if (M2C_FIELD(arg0, u8 *, 0x15B) & 1) {
        func_80971810();
        func_800B6490(arg0);
        return;
    }
block_4:
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x38E);
}
