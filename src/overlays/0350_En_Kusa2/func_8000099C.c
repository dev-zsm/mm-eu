// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0350.h"

M2C_UNK func_800B763C(s32, s32, M2C_UNK, M2C_UNK, f32, s32); /* extern */

void func_8000099C(EnKusa2 *this, PlayState *play) {
    func_800B763C(play, this, 0x41700000, 0x420C0000, 0.0f, 0x45);
}
