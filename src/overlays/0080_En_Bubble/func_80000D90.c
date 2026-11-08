// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0080.h"

M2C_UNK func_800E09D8(M2C_UNK, s32, s32, M2C_UNK);  /* extern */

void EnBubble_Destroy(Actor *thisx, PlayState *play) {
    func_800E09D8(play, (u8 *)thisx + 0x148, thisx, play);
}
