#include "types.h"

extern s32 Math3D_TriChkPointParaXImpl(void *a0, void *a1, s32 a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7);

s32 Math3D_TriChkPointParaXDeterminate(void *a0, void *a1, s32 a2, f32 a3, f32 a4, f32 a5, f32 a6) {
    return Math3D_TriChkPointParaXImpl(a0, a1, a2, a3, a4, a5, 1.0f, a6);
}
