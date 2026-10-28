// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BB6310(u8 *, M2C_UNK, M2C_UNK);    /* extern */
s32 func_80BB6880(u8 *);                          /* extern */
extern M2C_UNK D_80BB6A24;

void func_80000A10(u8 *arg0) {
    if (func_80BB6880(arg0) == 0) {
        func_80BB6310(arg0, 0, 0);
        M2C_FIELD(arg0, M2C_UNK **, 0x330) = &D_80BB6A24;
    }
}
