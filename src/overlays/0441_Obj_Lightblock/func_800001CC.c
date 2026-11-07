// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightblock.h"

void ObjLightblock_Wait(ObjLightblock* this, PlayState* play) {
    if (this->collider.base.acFlags & AC_HIT) {
        this->collider.base.acFlags &= ~AC_HIT;
        
        if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & (1 << 13)) {
            this->collisionCounter = 8;
        }
        
        else {
            this->collisionCounter++;
        }
    } else {
        this->collisionCounter = 0;
    }

    if (this->collisionCounter >= 8) {
        CutsceneManager_Queue(this->dyna.actor.csId);
        ObjLightblock_SetupPlayCutscene(this);
    } else {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
