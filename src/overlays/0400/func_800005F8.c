// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEE3C(u8 *, f32, M2C_UNK);        /* extern */
M2C_UNK func_800FFDD8(u8 *, s16, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80AA7ADC(u8 *, u8 *);              /* extern */

void func_800005F8(u8 *arg0, u8 *arg1) {
    u8 *sp24;

    sp24 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_80137070(arg0 + 0x148);
    func_800FEE3C(arg0 + 0x28, M2C_FIELD(arg0, f32 *, 0xC) - 99.0f, 0x40200000);
    func_800FFDD8(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 5, 0x1000);
    if ((M2C_FIELD(arg0, f32 *, 0x98) < 300.0f) && ((M2C_FIELD(sp24, f32 *, 0x28) - M2C_FIELD(arg0, f32 *, 0xC)) < 100.0f)) {
        func_80AA7ADC(arg0, arg1);
    }
}
