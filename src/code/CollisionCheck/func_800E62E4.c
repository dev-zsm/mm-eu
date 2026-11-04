// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_collision_check.h"

void CollisionCheck_AC(struct PlayState* play, CollisionCheckContext* colChkCtx, Collider* atCol) {
    Collider** acColP;

    for (acColP = &colChkCtx->colAC[0]; acColP < &colChkCtx->colAC[colChkCtx->colACCount]; acColP++) {
        Collider* acCol = *acColP;

        if ((acCol != NULL) && (acCol->acFlags & AC_ON)) {
            if ((acCol->actor != NULL) && (acCol->actor->update == NULL)) {
                continue;
            }
            if ((acCol->acFlags & atCol->atFlags & AC_TYPE_ALL) && (atCol != acCol)) {
                if (!(atCol->atFlags & AT_SELF) && (atCol->actor != NULL) && (acCol->actor == atCol->actor)) {
                    continue;
                }
                sACVsFuncs[atCol->shape][acCol->shape](play, colChkCtx, atCol, acCol);
            }
        }
    }
}
