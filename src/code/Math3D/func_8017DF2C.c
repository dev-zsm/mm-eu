#include "types.h"

extern s32 Math3D_TriChkPointParaZImpl(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g, f32 h);

s32 Math3D_TriChkPointParaZDeterminate(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g) {
    return Math3D_TriChkPointParaZImpl(a, b, c, d, e, f, 1.0f, g);
}
