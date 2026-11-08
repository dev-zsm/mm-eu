// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0643.h"

M2C_UNK func_800FF34C(u8 *, s32, u8 *, s32);    /* extern */

void ObjDanpeilift_UpdatePosition(ObjDanpeilift *this, s32 index) {
    func_800FF34C((u8 *)this + 0x24, M2C_FIELD(this, s32 *, 0x170) + (index * 6), this, index);
}
