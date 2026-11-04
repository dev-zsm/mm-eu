#include "types.h"

typedef struct {
    f32 mf[4][4];
} MtxF;

extern void SkinMatrix_SetTranslate(MtxF *mf, f32 x, f32 y, f32 z);
extern void SkinMatrix_SetRotateRPY(MtxF *mf, s16 x, s16 y, s16 z);
extern void SkinMatrix_MtxFMtxFMult(MtxF *mfA, MtxF *mfB, MtxF *dest);

void SkinMatrix_SetRotateRPYTranslate(MtxF *dest, s16 rotX, s16 rotY, s16 rotZ, f32 x, f32 y, f32 z) {
    MtxF rotation;
    MtxF translation;

    SkinMatrix_SetTranslate(&translation, x, y, z);
    SkinMatrix_SetRotateRPY(&rotation, rotX, rotY, rotZ);
    SkinMatrix_MtxFMtxFMult(&translation, &rotation, dest);
}
