// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0539.h"

M2C_UNK func_800B5BA4(s32, M2C_UNK);                /* extern */

void func_80000744(ObjNozoki *this, PlayState *play, s32 arg2, s32 arg3) {
    M2C_FIELD(this, s8 *, 0x15D) = arg2;
    M2C_FIELD(this, s8 *, 0x15E) = 0x50;
    func_800B5BA4(play, arg3);
}
