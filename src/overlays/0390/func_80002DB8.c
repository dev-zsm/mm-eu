// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_800B8400(u8 *, s32);                     /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
extern M2C_UNK D_80A9CAFC;

void func_80002DB8(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x148);
    func_80137070(arg0 + 0x2A0);
    if (func_800B8400(arg0, arg1) != 0) {
        M2C_FIELD(arg0, M2C_UNK **, 0x3E8) = &D_80A9CAFC;
    }
}
