// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0299.h"

M2C_UNK func_800F0308(s32, s32, M2C_UNK, M2C_UNK);  /* extern */

void func_800005C4(ObjFlowerpot *this, PlayState *play) {
    func_800F0308(play, (u8 *)this + 0x24, 0x14, 0x2887);
}
