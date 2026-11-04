// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_CylVsCylOverlapCenterDist(Cylinder16* ca, Cylinder16* cb, f32* overlapSize, f32* centerDist) {
    static Cylinderf sCaf;
    static Cylinderf sCbf;

    Math_Vec3s_ToVec3f(&sCaf.pos, &ca->pos);
    sCaf.radius = ca->radius;
    sCaf.yShift = ca->yShift;
    sCaf.height = ca->height;

    Math_Vec3s_ToVec3f(&sCbf.pos, &cb->pos);
    sCbf.radius = cb->radius;
    sCbf.yShift = cb->yShift;
    sCbf.height = cb->height;

    *centerDist = sqrtf(SQ(sCaf.pos.x - sCbf.pos.x) + SQ(sCaf.pos.z - sCbf.pos.z));

    
    if ((sCaf.radius + sCbf.radius) < *centerDist) {
        return false;
    }

    
    if ((((sCaf.pos.y + sCaf.yShift) + sCaf.height) < (sCbf.pos.y + sCbf.yShift)) ||
        (((sCbf.pos.y + sCbf.yShift) + sCbf.height) < (sCaf.pos.y + sCaf.yShift))) {
        return false;
    }

    *overlapSize = sCaf.radius + sCbf.radius - *centerDist;
    return true;
}
