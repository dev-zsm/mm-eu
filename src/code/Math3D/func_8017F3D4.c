// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_CylVsLineSeg(Cylinder16* cyl, Vec3f* linePointA, Vec3f* linePointB, Vec3f* intersectA, Vec3f* intersectB) {
    Vec3f cylToPtA;
    Vec3f cylToPtB;
    Vec3f ptAToPtB;
    f32 fracA;
    f32 fracB;
    f32 fracBase;
    f32 zero;
    f32 pad;
    f32 cylRadiusSq;
    f32 radSqDiff;
    f32 distCent2;
    f32 dot2AB;
    s32 sideIntA;
    s32 sideIntB;
    s32 intBeyondA;
    s32 intBeyondB;
    s32 intFlags;
    Vec3f intPts[4];
    s32 count;
    s32 i;

    fracA = 0.0f;
    fracB = 0.0f;

    zero = 0.0f;
    intFlags = 0;

    
    if (1) {}

    if (Math3D_PointInCyl(cyl, linePointA) && Math3D_PointInCyl(cyl, linePointB)) {
        
        *intersectA = *linePointA;
        *intersectB = *linePointB;
        return 2;
    }

    cylToPtA.x = linePointA->x - cyl->pos.x;
    cylToPtA.y = linePointA->y - cyl->pos.y - cyl->yShift;
    cylToPtA.z = linePointA->z - cyl->pos.z;
    cylToPtB.x = linePointB->x - cyl->pos.x;
    cylToPtB.y = linePointB->y - cyl->pos.y - cyl->yShift;
    cylToPtB.z = linePointB->z - cyl->pos.z;
    Math_Vec3f_Diff(&cylToPtB, &cylToPtA, &ptAToPtB);
    cylRadiusSq = SQ(cyl->radius);

     
    if (!IS_ZERO(ptAToPtB.y)) {
        
        fracBase = -cylToPtA.y / ptAToPtB.y;
        if ((fracBase >= 0.0f) && (fracBase <= 1.0f)) {
            f32 baseIntX = (ptAToPtB.x * fracBase) + cylToPtA.x;
            f32 baseIntZ = (ptAToPtB.z * fracBase) + cylToPtA.z;

            if ((SQ(baseIntX) + SQ(baseIntZ)) < cylRadiusSq) {
                
                intPts[0].x = cyl->pos.x + baseIntX;
                intPts[0].y = (f32)cyl->pos.y + cyl->yShift;
                intPts[0].z = cyl->pos.z + baseIntZ;
                intFlags |= 1;
            }
        }
        
        fracA = (cyl->height - cylToPtA.y) / ptAToPtB.y;
        if ((fracA >= 0.0f) && (fracA <= 1.0f)) {
            f32 topIntX = ptAToPtB.x * fracA + cylToPtA.x;
            f32 topIntZ = ptAToPtB.z * fracA + cylToPtA.z;

            if ((SQ(topIntX) + SQ(topIntZ)) < cylRadiusSq) {
                
                intPts[1].x = cyl->pos.x + topIntX;
                intPts[1].y = (f32)cyl->pos.y + cyl->yShift + cyl->height;
                intPts[1].z = cyl->pos.z + topIntZ;
                intFlags |= 2;
            }
        }
    }

     
    radSqDiff = SQXZ(cylToPtA) - cylRadiusSq;
    if (!IS_ZERO(2.0f * SQXZ(ptAToPtB))) {
        dot2AB = 2.0f * DOTXZ(ptAToPtB, cylToPtA);
        if (SQ(dot2AB) < (4.0f * SQXZ(ptAToPtB) * radSqDiff)) {
            
            return 0;
        }
        if ((SQ(dot2AB) - (4.0f * SQXZ(ptAToPtB) * radSqDiff)) > zero) {
            sideIntA = sideIntB = 1;
        } else {
            
            sideIntA = 1;
            sideIntB = 0;
        }
        distCent2 = sqrtf(SQ(dot2AB) - (4.0f * SQXZ(ptAToPtB) * radSqDiff));
        if (sideIntA != 0) {
            
            fracA = (distCent2 - dot2AB) / (2.0f * SQXZ(ptAToPtB));
        }
        if (sideIntB != 0) {
            
            fracB = (-dot2AB - distCent2) / (2.0f * SQXZ(ptAToPtB));
        }
    } else if (!IS_ZERO(2.0f * DOTXZ(ptAToPtB, cylToPtA))) {
        
        fracA = -radSqDiff / (2.0f * DOTXZ(ptAToPtB, cylToPtA));
        sideIntA = 1;
        sideIntB = 0;
    } else {
        return 0;
    }

    
    if (!sideIntB) {
        if ((fracA < 0.0f) || (fracA > 1.0f)) {
            return 0;
        }
    } else {
        intBeyondA = (fracA < 0.0f) || (fracA > 1.0f);
        intBeyondB = (fracB < 0.0f) || (fracB > 1.0f);
        if (intBeyondA && intBeyondB) {
            return 0;
        }
        if (intBeyondA) {
            sideIntA = 0;
        }
        if (intBeyondB) {
            sideIntB = 0;
        }
    }

    
    if ((sideIntA != 0) &&
        (((fracA * ptAToPtB.y + cylToPtA.y) < 0.0f) || (cyl->height < (fracA * ptAToPtB.y + cylToPtA.y)))) {
        sideIntA = 0;
    }
    if ((sideIntB != 0) &&
        (((fracB * ptAToPtB.y + cylToPtA.y) < 0.0f) || (cyl->height < (fracB * ptAToPtB.y + cylToPtA.y)))) {
        sideIntB = 0;
    }
    if ((sideIntA == 0) && (sideIntB == 0)) {
        return 0;
    }

    
    if (sideIntA != 0 && sideIntB != 0) {
        intPts[2].x = (fracA * ptAToPtB.x + cylToPtA.x) + cyl->pos.x;
        intPts[2].y = (fracA * ptAToPtB.y + cylToPtA.y) + cyl->pos.y + cyl->yShift;
        intPts[2].z = (fracA * ptAToPtB.z + cylToPtA.z) + cyl->pos.z;
        intFlags |= 4;
        intPts[3].x = (fracB * ptAToPtB.x + cylToPtA.x) + cyl->pos.x;
        intPts[3].y = (fracB * ptAToPtB.y + cylToPtA.y) + cyl->pos.y + cyl->yShift;
        intPts[3].z = (fracB * ptAToPtB.z + cylToPtA.z) + cyl->pos.z;
        intFlags |= 8;
    } else if (sideIntA != 0) {
        intPts[2].x = (fracA * ptAToPtB.x + cylToPtA.x) + cyl->pos.x;
        intPts[2].y = (fracA * ptAToPtB.y + cylToPtA.y) + cyl->pos.y + cyl->yShift;
        intPts[2].z = (fracA * ptAToPtB.z + cylToPtA.z) + cyl->pos.z;
        intFlags |= 4;
    } else if (sideIntB != 0) {
        intPts[2].x = (fracB * ptAToPtB.x + cylToPtA.x) + cyl->pos.x;
        intPts[2].y = (fracB * ptAToPtB.y + cylToPtA.y) + cyl->pos.y + cyl->yShift;
        intPts[2].z = (fracB * ptAToPtB.z + cylToPtA.z) + cyl->pos.z;
        intFlags |= 4;
    }

     
    for (count = 0, i = 0; i < ARRAY_COUNT(intPts); i++) {
        if (intFlags & (1 << i)) {
            if (count == 0) {
                *intersectA = intPts[i];
            } else if (count == 1) {
                if (Math3D_Vec3fDistSq(intersectA, linePointA) < Math3D_Vec3fDistSq(intersectA, &intPts[i])) {
                    *intersectB = intPts[i];
                } else {
                    *intersectB = *intersectA;
                    *intersectA = intPts[i];
                }
                break;
            }
            count++;
        }
    }
    return count;
}
