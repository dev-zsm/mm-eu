// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800F0308(s32, s32, M2C_UNK, M2C_UNK);  /* extern */

void func_80000D3C(s32 arg0, s32 arg1) {
    func_800F0308(arg1, arg0 + 0x24, 0x28, 0x28FD);
}
