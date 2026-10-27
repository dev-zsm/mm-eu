#include "types.h"

extern void SkinMatrix_SetTranslate(s32 a, s32 b, s32 c, s32 d);
extern void SkinMatrix_SetRotateYRP(f32 *m, s16 x, s16 y, s16 z);
extern void SkinMatrix_MtxFMtxFMult(f32 *a, f32 *b, f32 *c);
extern void SkinMatrix_SetScale(f32 *m, s32 x, s32 y, s32 z);

void SkinMatrix_SetScaleRotateYRPTranslate(f32 *dest, s32 sx, s32 sy, s32 sz, s16 rx, s16 ry, s16 rz, s32 tx, s32 ty, s32 tz) {
    f32 mf[16];
    f32 tmp[16];

    SkinMatrix_SetTranslate((s32)dest, tx, ty, tz);
    SkinMatrix_SetRotateYRP(mf, rx, ry, rz);
    SkinMatrix_MtxFMtxFMult((f32 *)dest, mf, tmp);
    SkinMatrix_SetScale(mf, sx, sy, sz);
    SkinMatrix_MtxFMtxFMult(tmp, mf, dest);
}
