// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test5.h"

void EnTest5_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnTest5* this = (EnTest5*)thisx;
    Vec3f steamPos;
    CollisionPoly* poly;
    s32 pad;

    this->actionFunc(this, play);

    
    if (ENTEST5_IS_HOT_SPRING(&this->actor) && ((play->state.frames % 4) == 0)) {
        steamPos.x = this->minPos.x + (Rand_ZeroOne() * this->xLength);
        steamPos.y = this->minPos.y + 100.0f;
        steamPos.z = this->minPos.z + (Rand_ZeroOne() * this->zLength);

        if ((BgCheck_EntityRaycastFloor2(play, &play->colCtx, &poly, &steamPos) + 10.0f) < this->minPos.y) {
            Vec3f steamVel;

            steamPos.y = this->minPos.y + 10.0f;
            steamVel.y = 0.5f;
            steamVel.x = 0.0f;
            steamVel.z = 0.0f;

            EffectSsIceSmoke_Spawn(play, &steamPos, &steamVel, &gZeroVec3f, -200 - (s32)(Rand_ZeroOne() * 50.0f));
        }
    }
}
