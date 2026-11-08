// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B763C(s32, u8 *, M2C_UNK, M2C_UNK, f32, s32); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */

void func_800014E0(Actor *thisx, PlayState *play) {
    func_800B680C(thisx);
    func_800B763C(play, thisx, 0x41F00000, 0x41700000, 0.0f, 5);
    func_800FFCBC((u8 *)thisx + 0xBE, M2C_FIELD(thisx, s16 *, 0x32), 3, 0x1F40, 0x64);
}
