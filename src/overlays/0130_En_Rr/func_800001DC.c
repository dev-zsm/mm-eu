// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0130.h"

M2C_UNK func_800E0FAC(s32, s32);                    /* extern */

void EnRr_Destroy(Actor *thisx, PlayState *play) {
    func_800E0FAC(play, (u8 *)thisx + 0x148);
    func_800E0FAC(play, (u8 *)thisx + 0x194);
}
