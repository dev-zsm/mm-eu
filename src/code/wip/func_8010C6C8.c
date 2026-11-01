#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

extern f32 D_801D5B84;

extern void OLib_Vec3fDiffRad(Vec2f *out);

// Remaining diff: the ROM puts the result at sp+0x18 and the 8-byte angles at sp+0x24; we get 0x1C and 0x28.
void OLib_Vec3fDiffDegF(Vec3f *out) {
    Vec2f angles;
    Vec3f result;

    OLib_Vec3fDiffRad(&angles);
    result.x = angles.x * D_801D5B84;
    result.y = angles.y * D_801D5B84;
    result.z = 0.0f;
    *out = result;
}
