// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

void Math_Vec3s_Copy(Vec3s *dst, Vec3s *src) {
    s16 x = src->x;
    s16 y = src->y;
    s16 z = src->z;

    dst->x = x;
    dst->y = y;
    dst->z = z;
}
