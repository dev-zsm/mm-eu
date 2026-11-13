// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ObjWarpstone_Update), score 7.00 (7 differ, size +3)
#include "generated/mm/z_obj_warpstone.h"

void func_800002CC(Actor* thisx, PlayState* play) {
    ObjWarpstone* this = (ObjWarpstone*)thisx;
    s32 pad;

    if (this->isTalking) {
        if (Actor_TextboxIsClosing(&this->dyna.actor, play)) {
            this->isTalking = false;
        } else {
#if MM_VERSION >= N64_US
            if ((Message_GetState(&play->msgCtx) == TEXT_STATE_CHOICE) && Message_ShouldAdvance(play)) {
                if (play->msgCtx.choiceIndex != 0) {
                    Audio_PlaySfx_MessageDecide();
                    play->msgCtx.msgMode = MSGMODE_OWL_SAVE_0;
                    play->msgCtx.unk120D6 = 0;
                    play->msgCtx.unk120D4 = 0;
                    gSaveContext.save.owlWarpId = OBJ_WARPSTONE_GET_OWL_WARP_ID(&this->dyna.actor);
                } else {
                    Message_CloseTextbox(play);
                }
            }
#endif
        }
    } else if (Actor_TalkOfferAccepted(&this->dyna.actor, &play->state)) {
        this->isTalking = true;
    } else if (!this->actionFunc(this, play)) {
        Actor_OfferTalkNearColChkInfoCylinder(&this->dyna.actor, play);
    }

    Collider_ResetCylinderAC(play, &this->collider.base);
    Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
