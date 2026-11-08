// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0358.h"

M2C_UNK func_800B763C(s32, s32, M2C_UNK, M2C_UNK, f32, s32); /* extern */

void func_80000C84(Actor *thisx, PlayState *play) {
    func_800B763C(play, thisx, 0x41000000, 0x41100000, 0.0f, 0x45);
}
