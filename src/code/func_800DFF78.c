#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    u8 pad0[0x80];
    Vec3f offset;
} QuakeSource;

Vec3f *Camera_GetQuakeOffset(Vec3f *dst, QuakeSource *src) {
    *dst = src->offset;
    return dst;
}
