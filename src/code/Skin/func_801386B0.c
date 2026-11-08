#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801ED340[];


void Skin_GetLimbPos(struct Skin *skin, s32 limbIndex, struct Vec3f *offset, struct Vec3f *dst) {
    u8 sp18[0x40];

    SkinMatrix_MtxFMtxFMult((u8 *)skin + 4, D_801ED340 + (limbIndex << 6), sp18);
    SkinMatrix_Vec3fMtxFMultXYZ(sp18, offset, dst);
}
