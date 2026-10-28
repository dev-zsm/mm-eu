// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_800E0FAC(s32, u8 *);                 /* extern */
M2C_UNK func_80138AB0(s32, u8 *);                 /* extern */
M2C_UNK func_801A818C(u8 *);                      /* extern */

void func_80001F6C(u8 *arg0, s32 arg1) {
    if (M2C_FIELD(arg0, s32 *, 0x1E8) & 0x08000000) {
        func_801A818C(arg0 + 0x218);
    }
    func_80138AB0(arg1, arg0 + 0x158);
    func_800E0FAC(arg1, arg0 + 0x278);
    func_800E0FAC(arg1, arg0 + 0x2C4);
    func_800E09D8(arg1, arg0 + 0x310);
}
