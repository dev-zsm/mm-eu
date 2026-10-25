#include "types.h"

extern u8 D_801ED340[];

extern void SkinMatrix_MtxFMtxFMult(void *src, void *limb, void *out);
extern void SkinMatrix_Vec3fMtxFMultXYZ(void *vec, s32 a, s32 b);

void Skin_GetLimbPos(u8 *skin, s32 limbIndex, s32 arg2, s32 arg3) {
    u8 sp18[0x40];

    SkinMatrix_MtxFMtxFMult(skin + 4, D_801ED340 + (limbIndex << 6), sp18);
    SkinMatrix_Vec3fMtxFMultXYZ(sp18, arg2, arg3);
}
