// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B83C0(u8 *, s32);                 /* extern */
M2C_UNK func_80151DF4(s32, M2C_UNK, u8 *);        /* extern */
M2C_UNK func_80BA272C(u8 *, s32);                 /* extern */
extern M2C_UNK D_80BA3DBC;

void func_80002520(u8 *arg0, s32 arg1) {
    if (func_800B8254(arg0, arg1) != 0) {
        func_80151DF4(arg1, 0x23A, arg0);
        M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80BA3DBC;
    } else if (M2C_FIELD(arg0, u8 *, 0x114) != 0) {
        func_800B83C0(arg0, arg1);
    }
    func_80BA272C(arg0, arg1);
}
