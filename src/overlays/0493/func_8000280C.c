// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B64E0(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_80B407DC(u8 *, u8 *, u8 *, M2C_UNK); /* extern */
M2C_UNK func_80B40868(u8 *, u8 *, M2C_UNK);     /* extern */

void func_8000280C(u8 *arg0) {
    u8 *sp24;
    u8 *temp_a0;

    M2C_FIELD(arg0, M2C_UNK (**)(u8 *), 0x144)(arg0);
    func_800B64E0(arg0, 0x41400000);
    func_80137070(arg0 + 0x148);
    temp_a0 = arg0 + 0x747;
    sp24 = temp_a0;
    func_80B40868(temp_a0, arg0 + 0x744, 0x3F333333);
    if (M2C_FIELD(arg0, u16 *, 0x32C) & 0x400) {
        func_80B407DC(arg0 + 0x368, arg0 + 0x378, sp24, 0xD2);
    }
}
