// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A36A18();                            /* extern */
M2C_UNK func_80A36D20();                            /* extern */

void func_80000B28(u8 *arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x1C) & 3;
    switch (temp_v0) {                              /* irregular */
    case 0:
        func_80A36A18();
        return;
    case 1:
    case 2:
        func_80A36D20();
        return;
    }
}
