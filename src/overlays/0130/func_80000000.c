// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void EnRr_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnRr* this = (EnRr*)thisx;

    Actor_ProcessInitChain(&this->actor, sInitChain);
    Collider_InitAndSetCylinder(play, &this->collider1, &this->actor, &sCylinderInit1);
    Collider_InitAndSetCylinder(play, &this->collider2, &this->actor, &sCylinderInit2);
    if (this->actor.params != LIKE_LIKE_PARAM_3) {
        this->actor.scale.y = 0.015f;
        this->actor.scale.x = 0.019f;
        this->actor.scale.z = 0.019f;
    } else {
        this->actor.scale.y = 0.022499999f;
        this->actor.scale.x = 0.028499998f;
        this->actor.scale.z = 0.028499998f;
        this->collider1.dim.radius *= 1.5f;
        this->collider1.dim.height *= 1.5f;
        this->collider2.dim.radius *= 1.5f;
        this->collider2.dim.height *= 1.5f;
        this->collider2.dim.yShift *= 1.5f;
    }

    Collider_UpdateCylinder(&this->actor, &this->collider2);
    Actor_SetFocus(&this->actor, this->actor.scale.y * 2000.0f);
    CollisionCheck_SetInfo(&this->actor.colChkInfo, &sDamageTable, &sColChkInfoInit);

    if ((this->actor.params == LIKE_LIKE_PARAM_2) || (this->actor.params == LIKE_LIKE_PARAM_3)) {
        this->actor.colChkInfo.health = 6;
        if (this->actor.params == LIKE_LIKE_PARAM_2) {
            this->actor.colChkInfo.mass = MASS_HEAVY;
        }
    }

    this->actionFunc = ref_func_808FAF94;
    ref_func_808FAD1C(this, play);
}
