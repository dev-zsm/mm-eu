// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_LineVsSph(Sphere16* sphere, Linef* line) {
    static Vec3f sSphLinePerpendicularPoint;
    Vec3f lineDiff;
    f32 temp_f0_2;
    f32 lineLenSq;

    if ((Math3D_PointInSph(sphere, &line->a)) || (Math3D_PointInSph(sphere, &line->b))) {
        
        return true;
    }
    lineDiff.x = line->b.x - line->a.x;
    lineDiff.y = line->b.y - line->a.y;
    lineDiff.z = line->b.z - line->a.z;

    lineLenSq = SQ(lineDiff.x) + SQ(lineDiff.y) + SQ(lineDiff.z);
    if (IS_ZERO(lineLenSq)) {
        
        return false;
    }
    temp_f0_2 = ((((sphere->center.x - line->a.x) * lineDiff.x) + ((sphere->center.y - line->a.y) * lineDiff.y)) +
                 ((sphere->center.z - line->a.z) * lineDiff.z)) /
                lineLenSq;
    if ((temp_f0_2 < 0.0f) || (temp_f0_2 > 1.0f)) {
        return false;
    }

    sSphLinePerpendicularPoint.x = (lineDiff.x * temp_f0_2) + line->a.x;
    sSphLinePerpendicularPoint.y = (lineDiff.y * temp_f0_2) + line->a.y;
    sSphLinePerpendicularPoint.z = (lineDiff.z * temp_f0_2) + line->a.z;

    if ((SQ(sSphLinePerpendicularPoint.x - sphere->center.x) + SQ(sSphLinePerpendicularPoint.y - sphere->center.y) +
         SQ(sSphLinePerpendicularPoint.z - sphere->center.z)) <= SQ((f32)sphere->radius)) {
        return true;
    }
    return false;
}
