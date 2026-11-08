// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0174.h"

s32 func_800B8400(u8 *, s32);                     /* extern */
M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
M2C_UNK func_8093F5C0(u8 *, s32);                 /* extern */

void func_800006E0(Actor *thisx, PlayState *play) {
    if (func_800B8400(thisx, play) != 0) {
        func_801A9868(0x110000FF);
        func_8093F5C0(thisx, play);
        M2C_FIELD(thisx, s32 *, 4) = (s32) (M2C_FIELD(thisx, s32 *, 4) & 0xFFFEFFFF);
    }
}
