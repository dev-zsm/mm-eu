// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80BE0AF4(u8 *, s32);                 /* extern */
s32 func_80BE0C10(u8 *, s32);                     /* extern */
s32 func_80BE0D4C(u8 *, s32);                     /* extern */
extern M2C_UNK D_80BE0F3C;

void func_80000D94(u8 *arg0, s32 arg1) {
    func_80BE0AF4(arg0, arg1);
    if ((func_80BE0C10(arg0, arg1) == 0) && (func_80BE0D4C(arg0, arg1) != 0)) {
        M2C_FIELD(arg0, M2C_UNK **, 0x430) = &D_80BE0F3C;
    }
}
