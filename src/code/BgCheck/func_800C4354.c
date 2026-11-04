// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bgcheck.h"

s32 BgCheck_CheckWallImpl(CollisionContext* colCtx, u16 xpFlags, Vec3f* posResult, Vec3f* posNext, Vec3f* posPrev,
                          f32 radius, CollisionPoly** outPoly, s32* outBgId, Actor* actor, f32 checkHeight, u8 argA) {
    StaticLookup* lookupTbl;
    s32 pad;
    s32 result;
    CollisionPoly* poly;
    
    f32 dx;
    f32 dy;
    f32 dz;
    Vec3f sphCenter;
    s32 dynaPolyCollision;
    Vec3f posIntersect;
    s32 bgId;
    f32 f32temp;

    result = false;
    *outBgId = BGCHECK_SCENE;
    *outPoly = NULL;
    lookupTbl = colCtx->lookupTbl;
    *posResult = *posNext;
    dx = posNext->x - posPrev->x;
    dy = posNext->y - posPrev->y;
    dz = posNext->z - posPrev->z;

    
    if (((dx != 0.0f) || (dz != 0.0f)) && !(argA & 1)) {
        if ((checkHeight + dy) < 5.0f) {
            
            result = BgCheck_CheckLineImpl(colCtx, xpFlags, COLPOLY_IGNORE_NONE, posPrev, posNext, &posIntersect, &poly,
                                           &bgId, actor, 1.0f, BGCHECK_CHECK_ALL & ~BGCHECK_CHECK_CEILING);
            if (result) {
                
                f32 ny = COLPOLY_GET_NORMAL(poly->normal.y);

                
                if (ny > 0.5f) {
                    posResult->x = posIntersect.x;
                    if (checkHeight > 1.0f) {
                        posResult->y = posIntersect.y - 1.0f;
                    } else {
                        posResult->y = posIntersect.y - checkHeight;
                    }
                    posResult->z = posIntersect.z;
                    if (actor != NULL) {
                        actor->bgCheckFlags |= BGCHECKFLAG_PLAYER_1000;
                    }
                }
                
                else {
                    f32 nx = COLPOLY_GET_NORMAL(poly->normal.x);
                    f32 nz = COLPOLY_GET_NORMAL(poly->normal.z);

                    posResult->x = radius * nx + posIntersect.x;
                    posResult->y = radius * ny + posIntersect.y;
                    posResult->z = radius * nz + posIntersect.z;
                }
                *outPoly = poly;
                *outBgId = bgId;
            }
        } else {
            
            Vec3f checkLineNext;
            Vec3f checkLinePrev;
            s32 pad;
            s32 bccFlags = SQ(radius) < (SQ(dx) + SQ(dz))
                               ? (BGCHECK_CHECK_ALL & ~BGCHECK_CHECK_CEILING)
                               : (BGCHECK_CHECK_ALL & ~BGCHECK_CHECK_FLOOR & ~BGCHECK_CHECK_CEILING);

            
            
            checkLineNext = *posNext;
            checkLineNext.y += checkHeight;
            checkLinePrev = *posPrev;
            checkLinePrev.y = checkLineNext.y;
            result = BgCheck_CheckLineImpl(colCtx, xpFlags, COLPOLY_IGNORE_NONE, &checkLinePrev, &checkLineNext,
                                           &posIntersect, &poly, &bgId, actor, 1.0f, bccFlags);

            if (result) {
                f32 nx2 = COLPOLY_GET_NORMAL(poly->normal.x);
                f32 nz2 = COLPOLY_GET_NORMAL(poly->normal.z);
                f32 n2XZDist = sqrtf(SQ(nx2) + SQ(nz2));

                
                if (!IS_ZERO(n2XZDist)) {
                    
                    f32 ny2;

                    f32temp = 1.0f / n2XZDist;
                    posResult->x = radius * f32temp * nx2 + posIntersect.x;
                    posResult->z = radius * f32temp * nz2 + posIntersect.z;
                    *outPoly = poly;
                    *outBgId = bgId;
                    ny2 = COLPOLY_GET_NORMAL(poly->normal.y);
                    result = true;
                    if (ny2 > 0.5f) {
                        if (actor != NULL) {
                            actor->bgCheckFlags |= BGCHECKFLAG_PLAYER_1000;
                        }
                    }
                } else {
                    result = false;
                }
            }
        }
    }

    sphCenter = *posResult;
    dynaPolyCollision = false;
    sphCenter.y += checkHeight;
    
    if (BgCheck_SphVsDynaWall(colCtx, xpFlags, &posResult->x, &posResult->z, &sphCenter, radius, outPoly, outBgId,
                              actor)) {
        result = true;
        dynaPolyCollision = true;
        sphCenter = *posResult;
        sphCenter.y += checkHeight;
    }
    
    if (BgCheck_PosInStaticBoundingBox(colCtx, posNext) &&
        
        
        BgCheck_SphVsStaticWall(BgCheck_GetNearestStaticLookup(colCtx, lookupTbl, posResult), colCtx, xpFlags,
                                &posResult->x, &posResult->z, &sphCenter, radius, outPoly, actor)) {
        *outBgId = BGCHECK_SCENE;
        result = true;
    }
    
    if (dynaPolyCollision || (*outBgId != BGCHECK_SCENE)) {
        Vec3f posIntersect2;
        s32 bgId2;

        if (BgCheck_CheckLineImpl(colCtx, xpFlags, COLPOLY_IGNORE_NONE, posPrev, posResult, &posIntersect2, &poly,
                                  &bgId2, actor, 1.0f, BGCHECK_CHECK_ONE_FACE | BGCHECK_CHECK_WALL)) {
            f32 nx3 = COLPOLY_GET_NORMAL(poly->normal.x);
            f32 nz3 = COLPOLY_GET_NORMAL(poly->normal.z);
            f32 n3XZDist = sqrtf(SQ(nx3) + SQ(nz3));

            
            if (!IS_ZERO(n3XZDist)) {
                
                f32temp = 1.0f / n3XZDist;
                posResult->x = radius * f32temp * nx3 + posIntersect2.x;
                posResult->z = radius * f32temp * nz3 + posIntersect2.z;
                *outPoly = poly;
                *outBgId = bgId2;
                result = true;
            }
        }
    }
    return result;
}
