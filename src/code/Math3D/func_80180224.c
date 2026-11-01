#include "types.h"
#include "code_funcs.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;


void Math3D_CylVsTri(s32 arg0, s32 arg1) {
    V3 sp1C;

    Math3D_CylTriVsIntersect(arg0, arg1, &sp1C);
}
