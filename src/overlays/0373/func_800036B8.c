// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_80A77F18();                            /* extern */
M2C_UNK func_80A7831C();                            /* extern */
M2C_UNK func_80A78668();                            /* extern */

void func_800036B8(Actor *thisx) {
    s16 temp_v0;

    if (M2C_FIELD(thisx, s16 *, 0x274) != 0) {
        temp_v0 = M2C_FIELD(thisx, s16 *, 0x276);
        switch (temp_v0) {                          /* irregular */
        case 1:
            func_80A77F18();
            return;
        case 0:
            func_80A7831C();
            return;
        case 2:
            func_80A78668();
            break;
        }
    }
}
