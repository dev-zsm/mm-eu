// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0262.h"

M2C_UNK func_800B6490(u8 *);                      /* extern */
s32 func_800FEE3C(u8 *, M2C_UNK, s32, u8 *);    /* extern */

void func_800004C0(Actor *thisx, s32 arg1) {
    if (func_800FEE3C((u8 *)thisx + 0x5C, 0x3BA3D70A, M2C_FIELD(thisx, s32 *, 0x158), thisx) != 0) {
        func_800B6490(thisx);
    }
}
