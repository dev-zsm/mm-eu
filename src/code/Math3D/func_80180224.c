#include "types.h"
#include "generated/code_funcs.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} V3;


s32 Math3D_CylVsTri(struct Cylinder16 *cyl, struct TriNorm *tri) {
    V3 sp1C;

    Math3D_CylTriVsIntersect(cyl, tri, &sp1C);
}
