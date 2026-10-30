// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_801342C8(s32, s32, s32, u8, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80B5A388;
extern M2C_UNK D_80B5A438;

void func_80001D1C(Actor *thisx, PlayState *play) {
    func_801342C8(play, M2C_FIELD(thisx, s32 *, 0x19C), M2C_FIELD(thisx, s32 *, 0x1B8), M2C_FIELD(thisx, u8 *, 0x19A), &D_80B5A388, &D_80B5A438, thisx);
}
