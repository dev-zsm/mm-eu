// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_twig.h"

void ref_func_80AC0AC8(EnTwig* this, PlayState* play) {
    static Vec3f ref_D_80AC10D0 = { 0.0f, 0.0f, 1.0f };
    Player* player = GET_PLAYER(play);
    Plane sp4C;
    Vec3f sp40;

    if (sCurrentRing == RACERING_GET_PARAM_FE0(&this->dyna.actor)) {
        if (this->unk_17A == 3) {
            this->unk_17A = 0;
            this->dyna.actor.shape.rot.z += 0x2000;
        } else {
            this->unk_17A++;
        }
    }
    SubS_ConstructPlane(&this->dyna.actor.world.pos, &ref_D_80AC10D0, &this->dyna.actor.shape.rot, &sp4C);
    if ((sCurrentRing == RACERING_GET_PARAM_FE0(&this->dyna.actor)) &&
        Math3D_LineSegVsPlane(sp4C.normal.x, sp4C.normal.y, sp4C.normal.z, sp4C.originDist, &this->unk_180,
                              &player->bodyPartsPos[PLAYER_BODYPART_WAIST], &sp40, 0)) {
        if (Math3D_Vec3fDistSq(&this->dyna.actor.world.pos, &sp40) <= SQ(this->dyna.actor.scale.x * 0.345f * 40.0f)) {
            ref_func_80AC0CC4(this, play);
            return;
        }
    } else {
        if (this->dyna.actor.xyzDistToPlayerSq <= SQ((this->dyna.actor.scale.x * 40.0f) + 40)) {
            DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        } else {
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        }
        if (this->dyna.actor.xyzDistToPlayerSq >= (this->dyna.actor.scale.x * 10.0f * 40.0f * 40.0f)) {
            this->dyna.actor.shape.rot.y = this->dyna.actor.yawTowardsPlayer;
            this->dyna.actor.world.rot.y = this->dyna.actor.yawTowardsPlayer;
        }
    }
    Math_Vec3f_Copy(&this->unk_180, &player->bodyPartsPos[PLAYER_BODYPART_WAIST]);
}
