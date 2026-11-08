// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

M2C_UNK Matrix_MultVec3f(s32, s32);                    /* extern */

void Actor_SetFeetPos(struct Actor *actor, s32 limbIndex, s32 leftFootIndex, struct Vec3f *leftFootPos, s32 rightFootIndex, struct Vec3f *rightFootPos) {
    if (limbIndex == leftFootIndex) {
        Matrix_MultVec3f(leftFootPos, (u8 *)actor + 0xD4);
        return;
    }
    if (limbIndex == rightFootIndex) {
        Matrix_MultVec3f(rightFootPos, (u8 *)actor + 0xE0);
    }
}
