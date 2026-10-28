// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(s32);                         /* extern */
M2C_UNK func_80A0CD18(u8 *, s32);                 /* extern */
M2C_UNK func_80A0DAB0(u8 *);                      /* extern */

void func_800017EC(u8 *arg0, s32 arg1) {
    func_80137070(arg0 + 0x144);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        func_800B8C4C(arg0, 0x38DD);
        func_80A0CD18(arg0, arg1);
        func_80A0DAB0(arg0);
    }
    M2C_FIELD(arg0, s16 *, 0xBC) = (s16) (M2C_FIELD(arg0, s16 *, 0xBC) + 0x800);
    M2C_FIELD(arg0, s16 *, 0xC0) = (s16) (M2C_FIELD(arg0, s16 *, 0xC0) + 0x1000);
}
