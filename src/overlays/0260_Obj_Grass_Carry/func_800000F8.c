// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0260.h"

M2C_UNK func_800B763C(s32, s32, M2C_UNK, M2C_UNK, f32, s32); /* extern */

void ObjGrassCarry_UpdateBgCheckInfo(ObjGrassCarry *this, PlayState *play) {
    func_800B763C(play, this, 0x40F00000, 0x420C0000, 0.0f, 0xC5);
}
