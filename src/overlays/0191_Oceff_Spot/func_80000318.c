// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_spot.h"

void OceffSpot_Update(Actor* thisx, PlayState* play) {
    f32 scale;
    s32 pad;
    Player* player = GET_PLAYER(play);
    f32 temp;
    OceffSpot* this = (OceffSpot*)thisx;

    temp = (1.0f - cosf(this->unk16C * M_PIf)) * 0.5f;
    this->actionFunc(this, play);

    switch (GET_PLAYER_FORM) {
        case PLAYER_FORM_DEKU:
            scale = 1.3f;
            break;

        case PLAYER_FORM_ZORA:
            scale = 1.2f;
            break;

        case PLAYER_FORM_GORON:
            scale = 2.0f;
            break;

        default:
            scale = 1.0f;
            break;
    }

    this->actor.scale.z = (scale * 0.42f) * temp;
    this->actor.scale.x = (scale * 0.42f) * temp;

    this->actor.world.pos = player->actor.world.pos;
    this->actor.world.pos.y += 5.0f;

    temp = (2.0f - this->unk16C) * this->unk16C;

    Environment_AdjustLights(play, temp * 0.5f, 880.0f, 0.2f, 0.9f);

    Lights_PointNoGlowSetInfo(&this->lightInfo1, this->actor.world.pos.x, this->actor.world.pos.y + 55.0f,
                              this->actor.world.pos.z, (s32)(255.0f * temp), (s32)(255.0f * temp), (s32)(200.0f * temp),
                              100.0f * temp);
    Lights_PointNoGlowSetInfo(
        &this->lightInfo2, this->actor.world.pos.x + (Math_SinS(player->actor.shape.rot.y) * 20.0f),
        this->actor.world.pos.y + 20.0f, this->actor.world.pos.z + (Math_CosS(player->actor.shape.rot.y) * 20.0f),
        (s32)(255.0f * temp), (s32)(255.0f * temp), (s32)(200.0f * temp), 100.0f * temp);
}
