// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0503.h"

M2C_UNK func_800C625C(s32, s32, s32, s32);          /* extern */
M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */

void BgKin2Fence_Destroy(Actor *thisx, PlayState *play) {
    func_800C625C(play, (u8 *)play + 0x880, M2C_FIELD(thisx, s32 *, 0x144), play);
    func_800E09D8(play, (u8 *)thisx + 0x15C);
}
