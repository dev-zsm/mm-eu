// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray3.h"

void MirRay3_Update(Actor* thisx, PlayState* play) {
    s32 pad[2];
    MirRay3* this = (MirRay3*)thisx;
    Player* player = GET_PLAYER(play);

    this->unk_210 &= ~1;

    if (this->unk_214 > 0.5f) {
        CollisionCheck_SetAT(play, &play->colChkCtx, &this->colliderQuad.base);
    }

    this->unk_210 &= ~2;

    if (Player_HasMirrorShieldEquipped(play)) {
        if (this->colliderCylinder.base.acFlags & AC_HIT) {
            this->unk_210 |= 2;
        }
        this->actor.world.pos.x = player->shieldMf.mf[3][0];
        this->actor.world.pos.y = player->shieldMf.mf[3][1];
        this->actor.world.pos.z = player->shieldMf.mf[3][2];
        Collider_UpdateCylinder(&this->actor, &this->colliderCylinder);
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderCylinder.base);
    }

    if (this->unk_214 > 0.1f) {
        Actor_PlaySfx_Flagged2(&player->actor, NA_SE_IT_SHIELD_BEAM - SFX_FLAG);
    }

    Math_ApproachZeroF(&this->unk_214, 1.0f, 0.1f);
}
