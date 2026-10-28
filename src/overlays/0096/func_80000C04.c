// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_808B7B70(s32, M2C_UNK *);              /* extern */
s32 func_808B86EC(s32);                             /* extern */
extern M2C_UNK D_808B87AC;

void func_80000C04(s32 arg0) {
    if (func_808B86EC(arg0) != 0) {
        func_808B7B70(arg0, &D_808B87AC);
    }
}
