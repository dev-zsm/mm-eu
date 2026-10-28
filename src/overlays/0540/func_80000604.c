// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400(u8 *, s32);                     /* extern */
M2C_UNK func_80B88460(u8 *, s32, u8);             /* extern */
M2C_UNK func_80B885DC(u8 *, s32);                 /* extern */
M2C_UNK func_80B88A28(u8 *);                      /* extern */
M2C_UNK func_80B899E4(u8 *, s32);                 /* extern */

void func_80000604(u8 *arg0, s32 arg1) {
    func_80B885DC(arg0, arg1);
    func_80B88A28(arg0);
    if (func_800B8400(arg0, arg1) != 0) {
        func_80B88460(arg0, arg1, M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x2B8), u8 *, 1));
        return;
    }
    func_80B899E4(arg0, arg1);
}
