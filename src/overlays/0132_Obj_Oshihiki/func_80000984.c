// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

s32 ObjOshihiki_CheckWall(PlayState* play, s16 angle, f32 direction, ObjOshihiki* this) {
    f32 maxDists[2];
    f32 maxDist;
    f32 sn;
    f32 cs;
    s32 i;
    Vec3f faceVtx;
    Vec3f faceVtxNext;
    Vec3f posResult;
    Vec3f faceVtxOffset;
    s32 bgId;
    CollisionPoly* outPoly;

    sn = Math_SinS(angle);
    cs = Math_CosS(angle);

    maxDists[0] = ((this->dyna.actor.scale.x * 300.0f) + 60.0f) - 0.5f;
    if (direction > 0.0f) {
        maxDists[1] = maxDists[0];
    } else {
        maxDists[0] = -maxDists[0];
        maxDists[1] = -(((this->dyna.actor.scale.x * 300.0f) + 90.0f) - 0.5f);
    }

    for (i = 0; i < ARRAY_COUNT(sFaceDirection); i++) {
        maxDist = maxDists[ref_D_80918940[i]];

        faceVtxOffset.x = (sFaceVtx[i].x * this->dyna.actor.scale.x * 10.0f) + sFaceDirection[i].x;
        faceVtxOffset.y = (sFaceVtx[i].z * this->dyna.actor.scale.y * 10.0f) + sFaceDirection[i].z;
        faceVtxOffset.z = 0.0f;

        ObjOshihiki_RotateXZ(&faceVtx, &faceVtxOffset, sn, cs);

        faceVtx.x += this->dyna.actor.world.pos.x;
        faceVtx.y += this->dyna.actor.world.pos.y;
        faceVtx.z += this->dyna.actor.world.pos.z;

        faceVtxNext.x = (maxDist * sn) + faceVtx.x;
        faceVtxNext.y = faceVtx.y;
        faceVtxNext.z = (maxDist * cs) + faceVtx.z;

        if (BgCheck_EntityLineTest3(&play->colCtx, &faceVtx, &faceVtxNext, &posResult, &outPoly, true, false, false,
                                    true, &bgId, &this->dyna.actor, 0.0f)) {
            return true;
        }
    }
    return false;
}
