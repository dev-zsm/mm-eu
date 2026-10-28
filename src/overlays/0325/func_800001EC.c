// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A212B0(u8 *);                      /* extern */
M2C_UNK func_80A213A8();                            /* extern */

void func_800001EC(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 0x398) = (s32) (M2C_FIELD(arg0, s32 *, 0x398) ^ 1);
    func_80A213A8();
    func_80A212B0(arg0);
}
