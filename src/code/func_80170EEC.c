// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800897D0(s32, M2C_UNK);                /* extern */
M2C_UNK ListAlloc_Init(s32);                         /* extern */

void func_80170EEC(s32 arg0) {
    func_800897D0(arg0, 0x50);
    ListAlloc_Init(arg0 + 0x44);
}
