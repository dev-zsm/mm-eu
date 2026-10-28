#include "types.h"

typedef struct {
    f32 m[4][4];
} MtxF;

extern MtxF *D_801F3644;
extern void SkinMatrix_SetScale(MtxF *, f32, f32, f32);

void Matrix_Scale(f32 x, f32 y, f32 z, s32 mode) {
    MtxF *cmf = D_801F3644;

    if (mode == 1) {
        cmf->m[0][0] *= x;
        cmf->m[0][1] *= x;
        cmf->m[0][2] *= x;
        cmf->m[1][0] *= y;
        cmf->m[1][1] *= y;
        cmf->m[1][2] *= y;
        cmf->m[2][0] *= z;
        cmf->m[2][1] *= z;
        cmf->m[2][2] *= z;
        cmf->m[0][3] *= x;
        cmf->m[1][3] *= y;
        cmf->m[2][3] *= z;
    } else {
        SkinMatrix_SetScale(cmf, x, y, z);
    }
}
