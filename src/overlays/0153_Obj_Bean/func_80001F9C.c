// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ObjBean_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjBean* this = (ObjBean*)thisx;

    if (this->unk_1B2 > 0) {
        this->unk_1B2--;
    }

    this->actionFunc(this, play);

    if (this->unk_1B4 > 0) {
        this->unk_1B4--;
        if (this->unk_1B4 == 0) {
            CutsceneManager_Stop(this->dyna.actor.csId);
        }
    }

    if (this->dyna.actor.draw != NULL) {
        ref_func_80937238(this);
        if (this->dyna.actor.xzDistToPlayer < 150.0f) {
            this->collider.dim.radius = (this->dyna.actor.scale.x * 640.0f) + 0.5f;
            Collider_UpdateCylinder(&this->dyna.actor, &this->collider);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
        }
        ref_func_80936CF0(this, play);
        this->dyna.actor.shape.shadowDraw = ActorShadow_DrawCircle;
        this->dyna.actor.shape.shadowScale = this->dyna.actor.scale.x * 88.0f;
        if (ref_func_80937468(this, play)) {
            ref_func_809375F4(this, play);
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
            ref_func_80938998(this);
        }
    } else {
        this->dyna.actor.shape.shadowDraw = NULL;
    }
    Actor_SetFocus(&this->dyna.actor, 6.0f);
}
