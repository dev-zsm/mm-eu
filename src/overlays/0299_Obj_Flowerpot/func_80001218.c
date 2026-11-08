// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0299.h"

M2C_UNK func_800B763C(s32, s32, M2C_UNK, M2C_UNK, f32, s32); /* extern */

void func_80001218(ObjFlowerpot *this, PlayState *play) {
    func_800B763C(play, this, 0x41900000, 0x41700000, 0.0f, 0x45);
}
