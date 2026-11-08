// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0462.h"

M2C_UNK func_800BDD44(M2C_UNK, s32, u8 *, M2C_UNK); /* extern */

void BgHakuginSwitch_Draw(Actor *thisx, PlayState *play) {
    func_800BDD44(play, M2C_FIELD(thisx, s32 *, 0x1A8), thisx, play);
}
