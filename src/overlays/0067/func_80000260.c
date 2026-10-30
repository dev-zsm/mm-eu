// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800B02EC(s32, s32);                    /* extern */
M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */

void func_80000260(Actor *thisx, PlayState *play) {
    func_800B02EC(play, M2C_FIELD(thisx, s32 *, 0x338));
    func_800E09D8(play, (u8 *)thisx + 0x654);
    func_800E09D8(play, (u8 *)thisx + 0x734);
    func_800E09D8(play, (u8 *)thisx + 0x3B4);
}
