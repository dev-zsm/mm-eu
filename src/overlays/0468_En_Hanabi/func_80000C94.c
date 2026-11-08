// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0468.h"

M2C_UNK func_800B6490(s32);                         /* extern */
s32 func_80B07C64(s32);                             /* extern */
M2C_UNK func_80B083F8(s32);                         /* extern */

void func_80000C94(EnHanabi *this) {
    func_80B083F8(this);
    if (func_80B07C64((u8 *)this + 0x148) == 0) {
        func_800B6490(this);
    }
}
