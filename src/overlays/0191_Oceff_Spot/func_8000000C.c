// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_spot.h"

void OceffSpot_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    OceffSpot* this = (OceffSpot*)thisx;
    Player* player = GET_PLAYER(play);

    Actor_ProcessInitChain(&this->actor, sInitChain);
    OceffSpot_SetupAction(this, OceffSpot_GrowCylinder);

    Lights_PointNoGlowSetInfo(&this->lightInfo1, this->actor.world.pos.x, this->actor.world.pos.y,
                              this->actor.world.pos.z, 0, 0, 0, 0);
    this->lightNode1 = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo1);

    Lights_PointNoGlowSetInfo(&this->lightInfo2, this->actor.world.pos.x, this->actor.world.pos.y,
                              this->actor.world.pos.z, 0, 0, 0, 0);
    this->lightNode2 = LightContext_InsertLight(play, &play->lightCtx, &this->lightInfo2);
    this->actor.scale.y = 0.3f;
    this->unk16C = 0.0f;
    this->actor.world.pos.y = player->actor.world.pos.y;
    this->actor.world.pos.x = player->bodyPartsPos[PLAYER_BODYPART_WAIST].x;
    this->actor.world.pos.z = player->bodyPartsPos[PLAYER_BODYPART_WAIST].z;
}
