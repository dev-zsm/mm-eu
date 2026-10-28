// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_80B4BD6C(u8 *, s32);                     /* extern */
M2C_UNK func_80B4C6B4(u8 *, s32);                 /* extern */
extern M2C_UNK D_80B4C94C;

void func_80001070(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x190);
    if (func_800B8254(arg0, arg1) != 0) {
        func_80B4C6B4(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x2A0) = &D_80B4C94C;
        return;
    }
    if (func_80B4BD6C(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s16 *, 0x116) = 0;
        func_800B8398(arg0, arg1, 0x42DC0000);
    }
}
