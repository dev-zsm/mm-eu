#include "types.h"
typedef struct { f32 f[16]; } Mtx4;
typedef struct { u8 pad0[0x28]; f32 eye[3]; f32 at[3]; f32 up[3]; u8 padE[0xE0-0x4C]; Mtx4 mtx; u8 pad120[4]; Mtx4 *p; } View;
extern void func_8008BB14(Mtx4 *, f32, f32, f32, f32, f32, f32, f32, f32, f32);
s32 View_UpdateViewingMatrix(View *v) {
    func_8008BB14(v->p, v->eye[0], v->eye[1], v->eye[2], v->at[0], v->at[1], v->at[2], v->up[0], v->up[1], v->up[2]);
    v->mtx = *v->p;
    v->p = &v->mtx;
    return 1;
}
