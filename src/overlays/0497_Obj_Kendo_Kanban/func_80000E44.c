// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kendo_kanban.h"

void ObjKendoKanban_UpdateCollision(ObjKendoKanban* this, PlayState* play) {
    if ((this->actionFunc != ObjKendoKanban_Tumble) && (this->actionFunc != ObjKendoKanban_Settled)) {
        if (this->colliderTris.base.acFlags & AC_HIT) {
            this->colliderTris.base.acFlags &= ~AC_HIT;
            ObjKendoKanban_SetupTumble(this, play);
        }

        Collider_UpdateCylinder(&this->actor, &this->colliderCylinder);
        this->colliderCylinder.dim.pos.z -= TRUNCF_BINANG(20.0f * Math_CosS(this->actor.shape.rot.y));
        this->colliderCylinder.dim.pos.x -= TRUNCF_BINANG(20.0f * Math_SinS(this->actor.shape.rot.y));

        if (this->actionFunc == ObjKendoKanban_DoNothing) {
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderTris.base);
        }
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->colliderCylinder.base);
    }
}
