// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B68A8(u8 *);                      /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80B5AE40(u8 *);                      /* extern */
M2C_UNK func_80B5AF2C(u8 *, s32);                 /* extern */
M2C_UNK func_80B5B620(u8 *, s32);                 /* extern */
extern u8 D_801E7F00;

void func_80000E24(u8 *arg0, s32 arg1) {
    func_80B5B620(arg0, arg1);
    func_80137070(arg0 + 0x148);
    M2C_FIELD(arg0, M2C_UNK (**)(u8 *, s32), 0x144)(arg0, arg1);
    func_80B5AE40(arg0);
    func_800B64E0(arg0, 0x42080000);
    if (!(D_801E7F00 & 1)) {
        func_80B5AF2C(arg0, arg1);
    }
    func_800B68A8(arg0);
}
