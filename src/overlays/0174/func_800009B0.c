// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801A3F5C(M2C_UNK);                     /* extern */
M2C_UNK func_8093F410(u8 *, s32);                 /* extern */
s32 func_8093F468(u8 *, s32, M2C_UNK, M2C_UNK, f32); /* extern */
extern M2C_UNK D_8093F950;

void func_800009B0(u8 *arg0, s32 arg1) {
    func_8093F410(arg0, arg1);
    if (func_8093F468(arg0, arg1, 0x7D0, 0x43B40000, 200.0f) != 0) {
        func_801A3F5C(0x45);
        M2C_FIELD(arg0, M2C_UNK **, 0x410) = &D_8093F950;
    }
}
