// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_800E09D8(s32, u8 *);                 /* extern */
M2C_UNK func_800E0FAC(s32, u8 *);                 /* extern */
M2C_UNK func_80102484(s32, s32, s32, s32);          /* extern */

void func_800001C8(Actor *thisx, PlayState *play) {
    func_80102484(play, (u8 *)play + 0x818, M2C_FIELD(thisx, s32 *, 0x318), play);
    func_800E09D8(play, (u8 *)thisx + 0x378);
    func_800E0FAC(play, (u8 *)thisx + 0x32C);
}
