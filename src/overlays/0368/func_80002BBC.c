// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mine.h"

void ObjMine_Path_Update(Actor* thisx, PlayState* play) {
    s32 pad; 
    ObjMine* this = (ObjMine*)thisx;

    if ((this->collider.base.ocFlags2 & OC2_HIT_PLAYER) || (this->collider.base.acFlags & AC_HIT)) {
        ObjMine_Path_SpawnBomb(this, play);
        ObjMine_SetupExplode(this);
    }

    this->actionFunc(this, play);

    if (this->actor.update != NULL) {
        this->collider.base.ocFlags1 &= ~OC1_HIT;
        this->collider.base.acFlags &= ~AC_HIT;
        this->collider.base.ocFlags2 &= ~OC2_HIT_PLAYER;
        if ((this->actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME) && (this->actionFunc != ObjMine_Explode)) {
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
        }
    }
}
