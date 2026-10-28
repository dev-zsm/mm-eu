// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_808932EC(u8 *, s32);                 /* extern */
M2C_UNK func_808935F4(u8 *);                      /* extern */

void func_80001E50(u8 *arg0, s32 arg1) {
    func_800FEC70(arg0 + 0xC0, 0, 0xFA0);
    func_80137070(arg0 + 0x144);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        M2C_FIELD(arg0, u8 *, 0x3BD) = (u8) (M2C_FIELD(arg0, u8 *, 0x3BD) | 1);
        M2C_FIELD(arg0, f32 *, 0xC4) = 0.0f;
        func_808932EC(arg0, arg1);
        func_808935F4(arg0);
    }
}
