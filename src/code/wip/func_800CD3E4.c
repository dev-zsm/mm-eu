// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"

typedef struct {
    f32 r;
    s16 pitch;
    s16 yaw;
} VecGeo;

extern void OLib_Vec3fToVecGeo(VecGeo* out, s32 a);
extern f32 Math_CosS(s16 a);
extern f32 func_800CAFC0(f32 a);

f32 Camera_CalcSlopeYAdj(s32 a0, s16 arg1, s16 arg2, f32 arg3) {
    f32 v;
    VecGeo geo;

    OLib_Vec3fToVecGeo(&geo, a0);
    v = Math_CosS(geo.pitch);
    v = func_800CAFC0(Math_CosS((s16)(arg1 - geo.yaw)) * v);
    return Math_CosS((s16)(arg1 - arg2)) * (v * arg3);
}
