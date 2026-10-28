// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80147B34(s32);                             /* extern */
M2C_UNK func_80151E7C(s32, M2C_UNK);                /* extern */
s32 func_801529DC(s32);                             /* extern */
extern M2C_UNK D_8093F844;

void func_800008F0(u8 *arg0, s32 arg1) {
    if ((func_801529DC(arg1 + 0x4908) == 5) && (func_80147B34(arg1) != 0)) {
        func_80151E7C(arg1, 0x7D2);
        M2C_FIELD(arg0, M2C_UNK **, 0x410) = &D_8093F844;
    }
}
