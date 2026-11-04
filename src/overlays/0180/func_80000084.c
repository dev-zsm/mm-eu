// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_stream.h"

s32 EnStream_PlayerIsInRange(Vec3f* vortexWorldPos, Vec3f* playerWorldPos, Vec3f* posDifference, f32 vortexYScale) {
    s32 ret = EN_STREAM_PLAYER_OUTSIDE_RANGE;
    f32 smallConstant = 28.0f;
    f32 upperBounds = 160 * vortexYScale * 50.0f;
    f32 lowerBounds = 0 * vortexYScale * 50.0f;
    f32 xzDist;
    f32 range;

    posDifference->x = playerWorldPos->x - vortexWorldPos->x;
    posDifference->y = playerWorldPos->y - vortexWorldPos->y;
    posDifference->z = playerWorldPos->z - vortexWorldPos->z;
    xzDist = sqrtf(SQ(posDifference->x) + SQ(posDifference->z));

    if (lowerBounds <= posDifference->y && posDifference->y <= upperBounds) {
        posDifference->y -= lowerBounds;

        range = ((75.0f - smallConstant) * (posDifference->y / (upperBounds - lowerBounds))) + 28.0f;
        if (xzDist <= range) {
            ret = EN_STREAM_PLAYER_WITHIN_RANGE_INSIDE_VORTEX;
        }
    }

    if (posDifference->y <= lowerBounds && xzDist <= 28.0f) {
        ret = EN_STREAM_PLAYER_WITHIN_RANGE_BELOW_VORTEX;
    }

    return ret;
}
