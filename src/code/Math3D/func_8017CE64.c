#include "types.h"
#include "code_funcs.h"

extern f32 D_801D79E8;

void Math3D_TriChkPointParaYSlopedY(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4) {
    Math3D_TriChkPointParaYImpl(a0, a1, a2, a3, a4, 300.0f, 1.0f, D_801D79E8);
}
