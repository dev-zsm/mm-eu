// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/sys_math3d.h"

s32 Math3D_CircleLineIntersections(f32 centreX, f32 centerY, f32 radius, f32 pointX, f32 pointY, f32 dirX, f32 dirY,
                                   f32* intersectAX, f32* intersectAY, f32* intersectBX, f32* intersectBY) {
    f32 a = SQ(dirX) + SQ(dirY); 
    f32 diffX = pointX - centreX;
    f32 diffY = pointY - centerY;
    f32 b;     
    f32 delta; 
    f32 rootP; 
    f32 rootN; 
    s32 ret;

    
    if ((IS_ZERO(dirX) && IS_ZERO(dirY)) || IS_ZERO(a)) {
        *intersectAX = 0.0f;
        *intersectAY = 0.0f;
        *intersectBX = 0.0f;
        *intersectBY = 0.0f;
        return 0;
    }

    b = 2.0f * (dirX * diffX + dirY * diffY); 
    delta = SQ(b) - 4.0f * a * (SQ(diffX) + SQ(diffY) - SQ(radius));
    ret = 0;

    if (IS_ZERO(delta)) { 
        
        rootN = -b / (2.0f * a);
        *intersectAX = dirX * rootN + pointX;
        *intersectAY = dirY * rootN + pointY;

        *intersectBX = 0.0f;
        *intersectBY = 0.0f;
    }

    if (delta > 0.0f) { 
        rootN = (-b - sqrtf(delta)) / (2.0f * a);
        *intersectAX = dirX * rootN + pointX;
        *intersectAY = dirY * rootN + pointY;

        rootP = (-b + sqrtf(delta)) / (2.0f * a);
        *intersectBX = dirX * rootP + pointX;
        *intersectBY = dirY * rootP + pointY;

        ret = 2;
    } else { 
        
        *intersectAX = 0.0f;
        *intersectAY = 0.0f;
    }

    return ret;
}
