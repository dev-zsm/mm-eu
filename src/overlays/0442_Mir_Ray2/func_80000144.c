// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray2.h"

void MirRay2_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    MirRay2* this = (MirRay2*)thisx;

    if (this->actor.home.rot.x <= 0) {
        this->range = 100.0f;
    } else {
        this->range = this->actor.home.rot.x * 4.0f;
    }
    Actor_SetScale(&this->actor, 1.0f);
    if (MIRRAY2_GET_F(&this->actor) != 1) {
        ActorShape_Init(&this->actor.shape, 0.0f, ActorShadow_DrawWhiteCircle, this->range * 0.02f);
    }
    ref_func_80AF3FE0(this, play);
    this->light = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo);
    Collider_InitJntSph(play, &this->collider);
    Collider_SetJntSph(play, &this->collider, &this->actor, &sJntSphInit, &this->elements);
    ref_func_80AF3F70(this);
    this->actor.shape.rot.x = 0;
    this->actor.world.rot.x = this->actor.shape.rot.x;
    if (MIRRAY2_GET_F(thisx) != 1) {
        if ((MIRRAY2_GET_SWITCH_FLAG(thisx) != 0x7F) && !Flags_GetSwitch(play, MIRRAY2_GET_SWITCH_FLAG(thisx))) {
            this->unk1A4 |= 1;
        }
    }
}
