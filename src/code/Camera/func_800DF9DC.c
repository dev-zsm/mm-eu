#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    u8 pad0[0x134];
    Vec3s inputDir;
} Camera;

Vec3s *Camera_GetInputDir(Vec3s *dst, Camera *camera) {
    *dst = camera->inputDir;
    return dst;
}
