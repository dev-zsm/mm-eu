// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_ana.h"

void DoorAna_WaitClosed(DoorAna* this, PlayState* play) {
    s32 grottoIsOpen = false;
    u32 grottoType = DOORANA_GET_TYPE(&this->actor);

    if (grottoType == DOORANA_TYPE_HIDDEN_STORMS) {
        
        if (this->actor.xyzDistToPlayerSq < SQ(200.0f) && CutsceneFlags_Get(play, 5)) {
            grottoIsOpen = true;
            this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED; 
        }

    } else {
        if (this->bombCollider.base.acFlags & AC_HIT) { 
            grottoIsOpen = true;
            Collider_DestroyCylinder(play, &this->bombCollider);

        } else {
            Collider_UpdateCylinder(&this->actor, &this->bombCollider);
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->bombCollider.base);
        }
    }

    if (grottoIsOpen) {
        DOORANA_SET_TYPE(&this->actor, DOORANA_TYPE_VISIBLE);
        DoorAna_SetupAction(this, DoorAna_WaitOpen);
        Audio_PlaySfx(NA_SE_SY_CORRECT_CHIME);
    }

    Actor_SetClosestSecretDistance(&this->actor, play);
}
