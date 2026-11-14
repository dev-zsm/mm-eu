// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_horse_link_child.h"

void func_80001554(Actor* thisx, PlayState* play) {
    s32 pad;
    EnHorseLinkChild* this = (EnHorseLinkChild*)thisx;

    sActionFuncs[this->action](this, play);

    Actor_MoveWithGravity(&this->actor);
    Actor_UpdateBgCheckInfo(play, &this->actor, 20.0f, 55.0f, 100.0f,
                            UPDBGCHECKINFO_FLAG_1 | UPDBGCHECKINFO_FLAG_4 | UPDBGCHECKINFO_FLAG_8 |
                                UPDBGCHECKINFO_FLAG_10);

    this->actor.focus.pos = this->actor.world.pos;
    this->actor.focus.pos.y += 70.0f;

    if ((Rand_ZeroOne() < 0.025f) && (this->eyeTexIndex == 0)) {
        this->eyeTexIndex++;
    } else if (this->eyeTexIndex > 0) {
        this->eyeTexIndex++;
        if (this->eyeTexIndex >= 4) {
            this->eyeTexIndex = 0;
        }
    }

    Collider_UpdateCylinder(&this->actor, &this->colldierCylinder);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->colldierCylinder.base);

    EnHorseLinkChild_PlaySound(this);
}
