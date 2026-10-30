// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012CA60(s32);                         /* extern */
M2C_UNK func_80134760(s32 *, s32, s32, u8, s32, s32, M2C_UNK *, u8 *); /* extern */
extern M2C_UNK D_80C02F08;

void func_800002AC(Actor *thisx, PlayState *play) {
    func_8012CA60(play->gfxCtx);
    func_80134760(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), M2C_FIELD(thisx, u8 *, 0x146), 0, 0, &D_80C02F08, thisx);
}
