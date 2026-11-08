// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0260.h"

M2C_UNK func_800A8248(s32, M2C_UNK, s32, s16);      /* extern */

void ObjGrassCarry_DropCollectible(Vec3f *pos, s16 dropTable, PlayState *play) {
    if (!(dropTable & 0x10)) {
        func_800A8248(play, 0, pos, (s16) (dropTable * 0x10));
    }
}
