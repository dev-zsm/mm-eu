// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B877C(u8 *, s32);                     /* extern */
M2C_UNK func_800B87A0(u8 *, s32, s32, s32, f32);  /* extern */
M2C_UNK func_80B40F74(u8 *, s32);                 /* extern */

void func_80000EEC(u8 *arg0, s32 arg1) {
    if (func_800B877C(arg0, arg1) != 0) {
        M2C_FIELD(arg0, s32 *, 0x120) = 0;
        func_80B40F74(arg0, arg1);
        func_80B40F74(M2C_FIELD(arg0, u8 **, 0x360), arg1);
        return;
    }
    func_800B87A0(arg0, arg1, M2C_FIELD(arg0, s32 *, 0x38C), M2C_FIELD(arg0, s32 *, 0x98), M2C_FIELD(arg0, f32 *, 0x9C));
}
