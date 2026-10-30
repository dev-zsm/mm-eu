// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E09D8(s32, s32);                    /* extern */
M2C_UNK func_800E0FAC(s32, s32);                    /* extern */

void func_800001E8(Actor *thisx, PlayState *play) {
    func_800E0FAC(play, (u8 *)thisx + 0x20C);
    func_800E0FAC(play, (u8 *)thisx + 0x258);
    func_800E09D8(play, (u8 *)thisx + 0x2A4);
}
