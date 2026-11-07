// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure2.h"

void ObjMure2_WaitForPlayerOutOfRange(ObjMure2* this, PlayState* play) {
    ObjMure2_ClearChildrenList(this);

    if ((sDeactivationRangesSq[OBJ_MURE2_GET_CHILD_TYPE(&this->actor)] * this->rangeMultiplier) <=
        Math3D_Dist1DSq(this->actor.projectedPos.x, this->actor.projectedPos.z)) {
        this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        ObjMure2_KillChildren(this, play);
        ObjMure2_SetupWaitForPlayerInRange(this);
    }
}
