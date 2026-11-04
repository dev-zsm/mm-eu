// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void EnKusa2_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnKusa2* this = (EnKusa2*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    if (!ENKUSA2_GET_1(&this->actor)) {
        this->actor.update = ref_func_80A5E604;
        this->actor.draw = NULL;
        this->actor.flags |= ACTOR_FLAG_DRAW_CULLING_DISABLED;
        Actor_ChangeCategory(play, &play->actorCtx, &this->actor, ACTORCAT_BG);
        this->unk_1BE = 0;
        if (ref_D_80A5EAEC) {
            ref_D_80A5EAEC = false;
            ref_D_80A60900 = play->gameplayFrames;
            ref_func_80A5CAD4(&ref_D_80A5F1C0);
            ref_D_80A60B08 = Rand_Next() >> 0x10;
            ref_D_80A60B0A = Rand_Next() >> 0x10;
            ref_D_80A60B0C = Rand_Next() >> 0x10;
            ref_D_80A60B0E = Rand_Next() >> 0x10;
            ref_D_80A60B10 = Rand_Next() >> 0x10;
            ref_func_80A5B508();
        }
        ref_func_80A5D5E0(this);
    } else {
        Collider_InitCylinder(play, &this->collider);
        if (!ref_func_80A5BA58(this, play)) {
            Actor_Kill(&this->actor);
            return;
        }

        Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);
        Collider_UpdateCylinder(&this->actor, &this->collider);
        this->actor.colChkInfo.mass = MASS_IMMOVABLE;
        this->unk_1CE = ref_D_80A5EAF0 & 7;
        ref_D_80A5EAF0++;
        this->actor.shape.shadowAlpha = 0;
        this->unk_1CF = 255;
        this->actor.shape.shadowScale = 1.0f;
        ref_func_80A5D7A4(this);
    }
}
