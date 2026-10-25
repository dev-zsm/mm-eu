#include "types.h"

extern f32 D_801D79E8;
extern void Math3D_TriChkPointParaYImpl(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7);

void Math3D_TriChkPointParaYSlopedY(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4) {
    Math3D_TriChkPointParaYImpl(a0, a1, a2, a3, a4, 300.0f, 1.0f, D_801D79E8);
}
