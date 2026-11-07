// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ObjSnowball_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjSnowball* this = (ObjSnowball*)thisx;
    s32 sp24 = false;

    if (this->actor.home.rot.y == 1) {
        if (this->unk_211 != 0) {
            if (Actor_TextboxIsClosing(&this->actor, play)) {
                this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
                this->unk_211 = 0;
            }
        } else if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
            this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
            this->unk_211 = 1;
        } else if (this->actor.isLockedOn) {
            sp24 = true;
        }
    }

    this->actionFunc(this, play);

    if (sp24 && (this->actionFunc == ref_func_80B04350)) {
        Actor_OfferTalk(&this->actor, play, 100.0f);
    }

    if ((this->actor.floorPoly != NULL) && (this->actor.projectedPos.z < 920.0f)) {
        if (this->actor.projectedPos.z > 400.0f) {
            this->actor.shape.shadowAlpha = (920 - (s32)this->actor.projectedPos.z) >> 2;
            this->actor.shape.shadowDraw = ActorShadow_DrawCircle;
        } else if (this->actor.projectedPos.z > -30.0f) {
            this->actor.shape.shadowAlpha = 130;
            this->actor.shape.shadowDraw = ActorShadow_DrawCircle;
        } else {
            this->actor.shape.shadowDraw = NULL;
        }
    } else {
        this->actor.shape.shadowDraw = NULL;
    }
}
