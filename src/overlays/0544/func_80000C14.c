// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
s32 func_80B94054(u8 *, s32);                     /* extern */
M2C_UNK func_80B94180(u8 *);                      /* extern */
M2C_UNK func_80B947E4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B9487C;

void func_80000C14(u8 *arg0, s32 arg1) {
    func_80B94180(arg0);
    if (func_800B8254(arg0, arg1) != 0) {
        func_80B947E4(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x29C) = &D_80B9487C;
        return;
    }
    if (func_80B94054(arg0, arg1) != 0) {
        func_800B8398(arg0, arg1, 0x43520000);
    }
}
