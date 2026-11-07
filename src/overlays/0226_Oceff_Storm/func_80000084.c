// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_oceff_storm.h"

void OceffStorm_Init(Actor* thisx, PlayState* play) {
    s32 pad[2];
    Player* player = GET_PLAYER(play);
    OceffStorm* this = (OceffStorm*)thisx;

    OceffStorm_SetupAction(this, OceffStorm_DefaultAction);

    this->posYOffAdd = 0;
    this->counter = 0;
    this->primColorAlpha = 0;
    this->vtxAlpha = 0;
    this->actor.scale.y = 0.0f;
    this->actor.scale.z = 0.0f;
    this->actor.scale.x = 0.0f;
    this->posYOff = this->posYOffAdd;

    if (this->actor.params == OCEFF_STORM_ACTION_PARAM_1) {
        OceffStorm_SetupAction(this, ref_func_80981B48);
        this->actor.draw = OceffStorm_Draw2;
    } else {
        this->actor.world.pos.y = player->actor.world.pos.y;
        this->actor.world.pos.x = player->bodyPartsPos[PLAYER_BODYPART_WAIST].x;
        this->actor.world.pos.z = player->bodyPartsPos[PLAYER_BODYPART_WAIST].z;
        gSaveContext.jinxTimer = 0;
        if ((play->interfaceCtx.restrictions.songOfStorms == 0) && !ref_func_8098176C(play)) {
            Actor_Spawn(&play->actorCtx, play, ACTOR_EN_OKARINA_EFFECT, this->actor.world.pos.x,
                        this->actor.world.pos.y - 30.0f, this->actor.world.pos.z, 0, 0, 0, 1);
        }
    }
}
