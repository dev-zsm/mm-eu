// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8254(u8 *, s32);                     /* extern */
M2C_UNK func_800B8398(u8 *, s32, M2C_UNK);        /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
s32 func_8094D8C0(u8 *, s32);                     /* extern */
M2C_UNK func_8094EB70(u8 *, s32);                 /* extern */
extern M2C_UNK D_8094E894;

void func_80001954(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (func_800B8254(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x2C4) = &D_8094E894;
        func_8094EB70(arg0, arg1);
        return;
    }
    if (func_8094D8C0(arg0, arg1) != 0) {
        func_800B8398(arg0, arg1, 0x42F00000);
    }
}
