// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "actor.h"

M2C_UNK func_8012C73C(s32);                         /* extern */
M2C_UNK func_8012C78C(s32);                         /* extern */
M2C_UNK func_80133EDC(u8 *, s32, s32, M2C_UNK *, s32, u8 *); /* extern */
extern M2C_UNK D_80A97308;

void func_8000080C(Actor *thisx, PlayState *play) {
    if ((M2C_FIELD(play, u8 *, 0x1F2C) != 0) && (M2C_FIELD(thisx, u8 *, 0x22E) != 0)) {
        func_8012C73C(M2C_FIELD(play, s32 *, 0));
        func_8012C78C(M2C_FIELD(play, s32 *, 0));
        func_80133EDC(play, M2C_FIELD(thisx, s32 *, 0x148), M2C_FIELD(thisx, s32 *, 0x164), &D_80A97308, 0, thisx);
    }
}
