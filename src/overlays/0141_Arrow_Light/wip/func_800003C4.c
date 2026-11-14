// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ArrowLight_Fly), score 6.00 (6 differ, size +3)
#include "generated/mm/z_arrow_light.h"

void func_800003C4(ArrowLight* this, PlayState* play) {
    EnArrow* arrow = (EnArrow*)this->actor.parent;
    s32 pad[2];

    if ((arrow == NULL) || (arrow->actor.update == NULL)) {
        Actor_Kill(&this->actor);
        return;
    }

    this->actor.world.pos = arrow->actor.world.pos;
    this->actor.shape.rot = arrow->actor.shape.rot;

    this->height = Math_Vec3f_DistXYZ(&this->firedPos, &this->actor.world.pos) * (1.0f / 24.0f);
    if (this->height < 1.0f) {
        this->height = 1.0f;
    }

    ArrowLight_Lerp(&this->firedPos, &this->actor.world.pos, 0.05f);

    if (arrow->unk_261 & 1) {
        Actor_PlaySfx(&this->actor, NA_SE_IT_EXPLOSION_LIGHT);
        ArrowLight_SetupAction(this, ArrowLight_Hit);
        this->timer = 32;
        this->alpha = 255;
        return;
    }
    if (arrow->unk_260 < 34) {
        if (this->alpha < 35) {
            Actor_Kill(&this->actor);
            return;
        }
        this->alpha -= 25;
    }
}
