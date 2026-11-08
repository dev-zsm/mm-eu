// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0259.h"

M2C_UNK func_800A8248(s32, M2C_UNK, u8 *, s16);   /* extern */

void ObjGrass_DropCollectible(void *grassElem, PlayState *play) {
    s8 temp_v0;

    temp_v0 = M2C_FIELD(grassElem, s8 *, 0xE);
    if (!(temp_v0 & 0x10)) {
        func_800A8248(play, 0, grassElem, (s16) (temp_v0 * 0x10));
    }
}
