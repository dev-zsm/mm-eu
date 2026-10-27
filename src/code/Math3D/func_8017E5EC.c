#include "types.h"
typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    Vec3f vtx[3];
    f32 nx, ny, nz, originDist;
} TriNorm;
extern s32 func_8017C908(Vec3f *, Vec3f *, Vec3f *, f32 *, f32 *, f32 *, f32 *);

s32 Math3D_TriNorm(TriNorm *tri, Vec3f *va, Vec3f *vb, Vec3f *vc) {
    tri->vtx[0] = *va;
    tri->vtx[1] = *vb;
    tri->vtx[2] = *vc;
    return func_8017C908(va, vb, vc, &tri->nx, &tri->ny, &tri->nz, &tri->originDist);
}
