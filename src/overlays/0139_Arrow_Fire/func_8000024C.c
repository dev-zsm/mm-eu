// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_arrow_fire.h"

void FireArrow_Hit(ArrowFire* this, PlayState* play) {
    f32 offset;
    f32 scale;
    u16 timer;

    if (this->actor.projectedW < 50.0f) {
        scale = 10.0f;
    } else if (this->actor.projectedW > 950.0f) {
        scale = 310.0f;
    } else {
        scale = this->actor.projectedW;
        scale = ((scale - 50.0f) * (1.0f / 3.0f)) + 10.0f;
    }

    timer = this->timer;
    if (timer != 0) {
        this->timer--;
        if (this->timer >= 8) {
            offset = (this->timer - 8) * (1.0f / 24.0f);
            offset = SQ(offset);
            this->radius = (((1.0f - offset) * scale) + 10.0f);
            this->height = F32_LERPIMP(this->height, 2.0f, 0.1f);
            if (this->timer < 16) {
                this->alpha = (this->timer * 35) - 280;
            }
        }
    }
    if (this->timer >= 9) {
        if (this->screenFillIntensity < 1.0f) {
            this->screenFillIntensity += 0.25f;
        }
    } else {
        if (this->screenFillIntensity > 0.0f) {
            this->screenFillIntensity -= 0.125f;
        }
    }
    if (this->timer < 8) {
        this->alpha = 0;
    }
    if (this->timer == 0) {
        this->timer = 255;
        Actor_Kill(&this->actor);
        return;
    }
    if (this->timer >= 13) {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider1.base);
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider2.base);
    }
}
