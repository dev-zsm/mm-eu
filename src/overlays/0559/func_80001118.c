// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
s32 func_80BAA78C(u8 *, s32);                     /* extern */
M2C_UNK func_80BAAB8C(u8 *);                      /* extern */
M2C_UNK func_80BAAD88(u8 *, s32);                 /* extern */

void func_80001118(u8 *arg0, s32 arg1) {
    func_80BAAB8C(arg0);
    func_80137070(arg0 + 0x1F0);
    func_800B64E0(arg0, 0x42280000);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x234)(arg0, arg1);
    if (func_80BAA78C(arg0, arg1) == 0) {
        func_80BAAD88(arg0, arg1);
    }
}
