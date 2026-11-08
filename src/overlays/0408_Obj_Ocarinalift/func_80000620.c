// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0408.h"

s32 func_800B849C(s32, s32);                        /* extern */
M2C_UNK func_800B8588(s32, s32, M2C_UNK);           /* extern */
s32 func_800CAD00(s32);                             /* extern */
M2C_UNK func_80152978(s32, M2C_UNK);                /* extern */
M2C_UNK func_80AAE878(s32);                         /* extern */

void func_80000620(ObjOcarinalift *this, s32 arg1) {
    if (func_800B849C(this, arg1) != 0) {
        func_80152978(arg1, 1);
        func_80AAE878(this);
        return;
    }
    if (func_800CAD00(this) != 0) {
        func_800B8588(this, arg1, 0x42200000);
    }
}
