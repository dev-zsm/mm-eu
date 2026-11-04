// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_storm.h"

void OceffStorm_DefaultAction(OceffStorm* this, PlayState* play) {
    f32 cylinderScale;

    switch (GET_PLAYER_FORM) {
        case PLAYER_FORM_DEKU:
            cylinderScale = 1.3f;
            break;

        case PLAYER_FORM_ZORA:
            cylinderScale = 1.2f;
            break;

        case PLAYER_FORM_GORON:
            cylinderScale = 2.0f;
            break;

        default:
            cylinderScale = 1.0f;
            break;
    }

    if (this->counter < 10) {
        this->primColorAlpha = (s8)(this->counter * 10.0f);
    } else if (this->counter > 60) {
        this->primColorAlpha = (s8)((70 - this->counter) * 10.0f);
    } else {
        this->primColorAlpha = 100;
    }

    if ((this->counter < 10) || (this->counter >= 60)) {
        this->vtxAlpha = 0;
    } else if (this->counter <= 40) {
        if (this->vtxAlpha <= 200) {
            this->vtxAlpha += 10;
        }
        this->actor.scale.x = this->actor.scale.z = 0.4f * cylinderScale;
        this->actor.scale.y = 0.3f;
    } else if (this->counter > 40) {
        this->vtxAlpha = (60 - this->counter) * 10;
    } else {
        this->actor.scale.x = this->actor.scale.z = 0.4f * cylinderScale;
        this->vtxAlpha = -1;
    }

    if (this->counter > 40) {
        this->actor.world.pos.y += this->posYOff * 0.01f;
        this->posYOff += this->posYOffAdd;
        this->posYOffAdd += 10;
    }

    if (this->counter < 70) {
        this->counter++;
    } else {
        Actor_Kill(&this->actor);
    }
}
