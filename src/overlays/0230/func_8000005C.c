// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80115F80(u8 *);                      /* extern */

void func_8000005C(s32 arg0, u8 *arg1) {
    func_80115F80(arg1);
    M2C_FIELD(arg1, s8 *, 0x169BC) = 0;
}
