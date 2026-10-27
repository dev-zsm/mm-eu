// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4f;

f32 Math3D_Plane(Vec4f *arg0, Vec4f *arg1) {
    return (arg0->x * arg1->x) + (arg0->y * arg1->y) + (arg0->z * arg1->z) + arg0->w;
}
