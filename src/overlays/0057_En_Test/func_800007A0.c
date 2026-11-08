// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0057.h"

M2C_UNK func_8018453C(s32, s32);                    /* extern */

void EnTest_Destroy(Actor *thisx, PlayState *play) {
    func_8018453C((u8 *)thisx + 0x144, thisx);
}
