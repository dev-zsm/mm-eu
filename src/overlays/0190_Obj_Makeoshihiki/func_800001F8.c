// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_makeoshihiki.h"

void ObjMakeoshihiki_Update(Actor* thisx, PlayState* play) {
    ObjMakeoshihiki* this = (ObjMakeoshihiki*)thisx;
    Actor* child;
    s32 loopPathIndex;
    Vec3f pathPointF;

    child = this->actor.child;
    if (child != NULL) {
        if (child->update == NULL) {
            this->actor.child = NULL;
        } else {
            for (loopPathIndex = 0; loopPathIndex < this->pathCount; loopPathIndex++) {
                Math_Vec3s_ToVec3f(&pathPointF, &this->pathPoints[loopPathIndex]);
                if (Math3D_Vec3fDistSq(&this->actor.child->world.pos, &pathPointF) < SQ(0.5f)) {
                    ObjMakeoshihiki_SetSwitchFlags(this, play, loopPathIndex);
                    return;
                }
            }
        }
    }
}
