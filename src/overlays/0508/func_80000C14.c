// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80B5B654(s32);                         /* extern */
M2C_UNK func_80B5B6B0(s32, u8 *);                 /* extern */

void func_80000C14(s32 arg0, u8 *arg1) {
    u8 *sp1C;

    sp1C = M2C_FIELD(arg1, u8 **, 0x1CCC);
    func_80B5B654(arg0);
    func_80B5B6B0(arg0, arg1);
    M2C_FIELD(sp1C, s32 *, 0xA74) = (s32) (M2C_FIELD(sp1C, s32 *, 0xA74) | 0x400);
}
