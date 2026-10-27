// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK ActorShadow_Draw(void *, s32, s32, M2C_UNK *, s32); /* extern */
M2C_UNK func_800B4A5C(s32, void *, M2C_UNK);        /* extern */
extern M2C_UNK D_4075A40;

void ActorShadow_DrawSquare(void *arg0, s32 arg1, s32 arg2) {
    if (M2C_FIELD(arg0, u16 *, 0x90) & 0x400) {
        func_800B4A5C(arg2, arg0, 0x42480000);
    }
    ActorShadow_Draw(arg0, arg1, arg2, &D_4075A40, 0);
}
