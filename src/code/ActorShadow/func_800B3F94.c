// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK ActorShadow_Draw(void *, s32, s32, M2C_UNK *, s32); /* extern */
M2C_UNK func_800B4A5C(s32, void *, M2C_UNK);        /* extern */
extern M2C_UNK D_4075A40;

void ActorShadow_DrawSquare(struct Actor *actor, struct Lights *lights, struct PlayState *play) {
    if (M2C_FIELD(actor, u16 *, 0x90) & 0x400) {
        func_800B4A5C(play, actor, 0x42480000);
    }
    ActorShadow_Draw(actor, lights, play, &D_4075A40, 0);
}
