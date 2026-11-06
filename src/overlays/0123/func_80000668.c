// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_SetIntensity(MirRay* this, PlayState* play) {
    f32 sp4C[3];
    s32 pad[4];
    Player* player = GET_PLAYER(play);
    MtxF* shieldMtx = &player->shieldMf;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    this->reflectIntensity = 0.0f;

    if (MirRay_CheckInFrustum(&this->sourcePt, &this->poolPt, shieldMtx->xw, shieldMtx->yw, shieldMtx->zw,
                              this->sourceEndRad, this->poolEndRad)) {
        temp_f0 = sqrtf(SQ(shieldMtx->zz) + (SQ(shieldMtx->xz) + SQ(shieldMtx->yz)));
        if (temp_f0 == 0.0f) {
            this->reflectRange = 1.0f;
        } else {
            this->reflectRange = 1.0f / temp_f0;
        }

        if (sMirRayData[MIRRAY_LOCATION(&this->actor)].params & 1) {
            this->reflectIntensity = 1.0f;
        } else {
            sp4C[0] = this->poolPt.x - this->sourcePt.x;
            sp4C[1] = this->poolPt.y - this->sourcePt.y;
            sp4C[2] = this->poolPt.z - this->sourcePt.z;

            temp_f2 = (-shieldMtx->xz * sp4C[0]) - (shieldMtx->yz * sp4C[1]) - (shieldMtx->zz * sp4C[2]);

            if (temp_f2 < 0.0f) {
                temp_f0_2 = sqrtf(SQ(sp4C[0]) + SQ(sp4C[1]) + SQ(sp4C[2]));
                if ((temp_f0 != 0.0f) && (temp_f0_2 != 0.0f)) {
                    this->reflectIntensity = -temp_f2 / (temp_f0 * temp_f0_2);
                }
            }
        }
    }
}
