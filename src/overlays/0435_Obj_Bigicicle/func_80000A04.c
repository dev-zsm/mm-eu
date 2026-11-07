// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ObjBigicicle_Update(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjBigicicle* this = (ObjBigicicle*)thisx;
    Vec3f sp44;

    this->actionFunc(this, play);

    if (Rand_ZeroOne() < 0.05f) {
        sp44.x = (((215.0f + Rand_ZeroFloat(65.0f)) * ((Rand_ZeroOne() < 0.5f) ? -1 : 1)) * this->actor.scale.x) +
                 this->actor.world.pos.x;
        sp44.y = ((((Rand_ZeroFloat(1400.0f) + -150.0f) - 2100.0f) + this->actor.shape.yOffset) * this->actor.scale.y) +
                 this->actor.world.pos.y;
        sp44.z = (((215.0f + Rand_ZeroFloat(65.0f)) * ((Rand_ZeroOne() < 0.5f) ? -1 : 1)) * this->actor.scale.z) +
                 this->actor.world.pos.z;

        EffectSsKirakira_SpawnDispersed(play, &sp44, &gZeroVec3f, &gZeroVec3f, &ref_D_80AE9894, &ref_D_80AE9898, 2000, 5);
    }

    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider1.base);
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider2.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider1.base);
    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider2.base);
}
