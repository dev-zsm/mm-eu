// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E09D8(s32, s32);                    /* extern */
M2C_UNK func_800E0FAC(s32, s32);                    /* extern */
M2C_UNK func_801A3D9C();                            /* extern */

void func_80000208(Actor *thisx, PlayState *play) {
    func_800E0FAC(play, (u8 *)thisx + 0x6F4);
    func_800E09D8(play, (u8 *)thisx + 0x454);
    if (M2C_FIELD(thisx, s16 *, 0x74A) != 2) {
        func_801A3D9C();
    }
}
