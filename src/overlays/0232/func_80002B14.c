// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_801529DC(s32);                             /* extern */
M2C_UNK func_8096DE80(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_809707A4;
extern M2C_UNK D_8097109C;

void func_80002B14(u8 *arg0, s32 arg1) {
    if (func_801529DC(arg1 + 0x4908) == 2) {
        func_8096DE80(arg0 + 0x14C, &D_8097109C, 0);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809707A4;
    }
}
