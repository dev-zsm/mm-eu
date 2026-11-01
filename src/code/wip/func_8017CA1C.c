#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

f32 Math3D_PlaneF(f32 arg0, f32 arg1, f32 arg2, f32 arg3, Vec3f *arg4) {
    return (arg4->x * arg0) + (arg1 * arg4->y) + (arg2 * arg4->z) + arg3;
}
