// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0139.h"

M2C_UNK func_800E1C28(s32, s32);                    /* extern */
M2C_UNK func_80115F80(s32);                         /* extern */

void ArrowFire_Destroy(Actor *thisx, PlayState *play) {
    func_80115F80(play);
    func_800E1C28(play, (u8 *)thisx + 0x144);
    func_800E1C28(play, (u8 *)thisx + 0x1C4);
}
