#include "types.h"

extern void Math3D_TriChkPointParaYImpl(void *a0, void *a1, void *a2, f32 a3, f32 a4, f32 a5, f32 a6, f32 a7);

void Math3D_TriChkPointParaYDeterminate(void *a0, void *a1, void *a2, f32 a3, f32 a4, f32 a5, f32 a6) {
    Math3D_TriChkPointParaYImpl(a0, a1, a2, a3, a4, a5, 1.0f, a6);
}
