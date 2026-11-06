// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightswitch_Update(Actor* thisx, PlayState* play) {
    ObjLightswitch* this = (ObjLightswitch*)thisx;
    s32 pad;

    if (this->collider.base.acFlags & AC_HIT) {
        
        if ((this->collider.elements[0].base.acHitElem->atDmgInfo.dmgFlags & 0x2000) != 0) {
            this->hitState = 10;
        } else if (LIGHTSWITCH_GET_TYPE(&this->actor) == LIGHTSWITCH_TYPE_FLIP) {
            if (this->hitState == 0) {
                if ((this->previousACFlags & AC_HIT) == 0) {
                    this->hitState = 1;
                }
            } else if (this->hitState < 10) {
                this->hitState++;
            }
        } else {
            if (this->hitState < 10) {
                this->hitState++;
            }
        }
    } else {
        this->hitState = 0;
    }

    
    if ((this->cutsceneTimer > 0) && (this->actionFunc != ObjLightswitch_PlayCinema)) {
        this->cutsceneTimer--;
        if (this->cutsceneTimer == 0) {
            CutsceneManager_Stop(this->actor.csId);
        }
    }

    this->actionFunc(this, play);
    if (this->actor.update != NULL) {
        this->previousACFlags = this->collider.base.acFlags;
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
