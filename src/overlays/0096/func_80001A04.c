// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_808B7B70(u8 *, M2C_UNK *);           /* extern */
extern M2C_UNK D_808B95B8;

void func_80001A04(u8 *arg0, s32 arg1) {
    if (func_801529DC(arg1 + 0x4908) == 2) {
        M2C_FIELD(arg0, s16 *, 0x1CE) = 0x6E;
        func_808B7B70(arg0, &D_808B95B8);
    }
}
