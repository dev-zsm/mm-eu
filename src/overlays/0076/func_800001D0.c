// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B02EC(s32, s32);                    /* extern */
M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_800E1C28(s32, u8 *);                 /* extern */

void func_800001D0(Actor *thisx, PlayState *play) {
    func_800B02EC(play, M2C_FIELD(thisx, s32 *, 0x2A0));
    func_800E09D8(play, (u8 *)thisx + 0x364);
    func_800E1C28(play, (u8 *)thisx + 0x5C4);
}
