// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8364(u8 *, s32, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80151DF4(s32, u16, u8 *);            /* extern */
extern M2C_UNK D_80B97574;

void func_80001BDC(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151DF4(arg1, M2C_FIELD(arg0, u16 *, 0x496), arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B97574;
        return;
    }
    func_800B8364(arg0, arg1, 0x43C80000, -1);
}
