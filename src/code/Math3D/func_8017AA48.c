// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_LineSegMakePerpLineSeg(Vec3f* lineAPointA, Vec3f* lineAPointB, Vec3f* lineBPointA, Vec3f* lineBPointB,
                                  Vec3f* lineAClosestToB, Vec3f* lineBClosestToA) {
    f32 magSq;
    f32 scaleB;
    f32 lineAx = lineAPointB->x - lineAPointA->x;
    f32 lineAy = lineAPointB->y - lineAPointA->y;
    f32 lineAz = lineAPointB->z - lineAPointA->z;
    f32 lineBx = lineBPointB->x - lineBPointA->x;
    f32 lineBy = lineBPointB->y - lineBPointA->y;
    f32 lineBz = lineBPointB->z - lineBPointA->z;
    f32 compAAlongB;
    f32 compBAAlongB;
    Vec3f lineAPerpB;
    Vec3f lineBAPerpB;
    f32 tA;
    f32 tB;

    magSq = SQ(lineBx) + SQ(lineBy) + SQ(lineBz);
    if (IS_ZERO(magSq)) {
        return false;
    }

    scaleB = 1.0f / magSq;

    compAAlongB = ((lineAx * lineBx) + (lineAy * lineBy) + (lineAz * lineBz)) * scaleB;

    compBAAlongB = ((lineBx * (lineAPointA->x - lineBPointA->x)) + (lineBy * (lineAPointA->y - lineBPointA->y)) +
                    (lineBz * (lineAPointA->z - lineBPointA->z))) *
                   scaleB;

    lineAPerpB.x = lineAx - (lineBx * compAAlongB);
    lineAPerpB.y = lineAy - (lineBy * compAAlongB);
    lineAPerpB.z = lineAz - (lineBz * compAAlongB);

    magSq = SQXYZ(lineAPerpB);
    if (IS_ZERO(magSq)) {
        return false;
    }

    lineBAPerpB.x = (lineAPointA->x - lineBPointA->x) - (lineBx * compBAAlongB);
    lineBAPerpB.y = (lineAPointA->y - lineBPointA->y) - (lineBy * compBAAlongB);
    lineBAPerpB.z = (lineAPointA->z - lineBPointA->z) - (lineBz * compBAAlongB);

    tA = -DOTXYZ(lineAPerpB, lineBAPerpB) / magSq;
    lineAClosestToB->x = (lineAx * tA) + lineAPointA->x;
    lineAClosestToB->y = (lineAy * tA) + lineAPointA->y;
    lineAClosestToB->z = (lineAz * tA) + lineAPointA->z;

    tB = (compAAlongB * tA) + compBAAlongB;
    lineBClosestToA->x = (lineBx * tB) + lineBPointA->x;
    lineBClosestToA->y = (lineBy * tB) + lineBPointA->y;
    lineBClosestToA->z = (lineBz * tB) + lineBPointA->z;

    return true;
}
