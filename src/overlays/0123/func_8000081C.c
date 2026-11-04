// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_mir_ray.h"

void MirRay_SetupReflectionPolys(MirRay* this, PlayState* play, MirRayShieldReflection* reflection) {
    s32 i;
    Player* player = GET_PLAYER(play);
    MtxF* shieldMtx = &player->shieldMf;
    Vec3f posA;
    Vec3f posB;
    Vec3f sp70;
    CollisionPoly* outPoly;
    f32 sp60[3];

    sp60[0] = -(shieldMtx->xz * this->reflectRange) * this->reflectIntensity * 400.0f;
    sp60[1] = -(shieldMtx->yz * this->reflectRange) * this->reflectIntensity * 400.0f;
    sp60[2] = -(shieldMtx->zz * this->reflectRange) * this->reflectIntensity * 400.0f;

    for (i = 0; i < ARRAY_COUNT(this->shieldCorners); i++) {
        posA.x =
            (shieldMtx->xw + (this->shieldCorners[i].x * shieldMtx->xx)) + (this->shieldCorners[i].y * (*shieldMtx).xy);
        posA.y =
            (shieldMtx->yw + (this->shieldCorners[i].x * shieldMtx->yx)) + (this->shieldCorners[i].y * (*shieldMtx).yy);
        posA.z =
            (shieldMtx->zw + (this->shieldCorners[i].x * shieldMtx->zx)) + (this->shieldCorners[i].y * (*shieldMtx).zy);

        posB.x = sp60[0] + posA.x;
        posB.y = sp60[1] + posA.y;
        posB.z = sp60[2] + posA.z;

        if (BgCheck_AnyLineTest1(&play->colCtx, &posA, &posB, &sp70, &outPoly, true)) {
            reflection[i].reflectionPoly = outPoly;
        } else {
            reflection[i].reflectionPoly = NULL;
        }
    }
}
