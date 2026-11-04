#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    s16 x, y, z;
} Vec3s;

typedef struct {
    Vec3f scale;
    Vec3s rot;
    Vec3f pos;
} ScaleRotPos;

void ScaleRotPos_SetValue(ScaleRotPos *dst, Vec3f *scale, Vec3s *rot, Vec3f *pos) {
    dst->scale = *scale;
    dst->rot = *rot;
    dst->pos = *pos;
}
