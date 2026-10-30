// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_801342C8(s32, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_80A9E704(u8 *, s32);                 /* extern */
extern M2C_UNK D_80A9E3D0;
extern M2C_UNK D_80A9E46C;

void func_80004E38(Actor *thisx, PlayState *play) {
    func_80A9E704(thisx, play);
    func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x14C), M2C_FIELD(thisx, s32 *, 0x168), M2C_FIELD(thisx, u8 *, 0x14A), &D_80A9E3D0, &D_80A9E46C, thisx);
}
