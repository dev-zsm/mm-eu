// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_80134760(s32 *, s32, s32, u8, M2C_UNK *, M2C_UNK *, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80BB15C8;
extern M2C_UNK D_80BB176C;
extern M2C_UNK D_80BB1784;

void func_80001EBC(Actor *thisx, PlayState *play) {
    func_8012C73C(play->gfxCtx);
    func_80134760(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), M2C_FIELD(thisx, u8 *, 0x146), &D_80BB15C8, &D_80BB176C, &D_80BB1784, thisx);
}
