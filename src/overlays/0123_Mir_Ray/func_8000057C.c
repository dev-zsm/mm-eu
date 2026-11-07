// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    MirRay* this = (MirRay*)thisx;
    Player* player = GET_PLAYER(play);

    ref_D_808E3BF0 = false;

    if (!this->unLit) {
        if (sMirRayData[MIRRAY_LOCATION(&this->actor)].params & 2) {
            if (sMirRayData[MIRRAY_LOCATION(&this->actor)].params & 4) {
                MirRay_SetupCollider(this);
            }
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider1.base);
        }

        if (this->reflectIntensity > 0.0f) {
            CollisionCheck_SetAT(play, &play->colChkCtx, &this->collider2.base);
        }

        MirRay_MakeShieldLight(this, play);

        if (this->reflectIntensity > 0.0f) {
            Actor_PlaySfx_Flagged2(&player->actor, NA_SE_IT_SHIELD_BEAM - SFX_FLAG);
        }
    }
}
