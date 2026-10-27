#include "types.h"
extern f32 D_801D6930;
typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    u8 pad0[0x28];
    Vec3f eye;
    Vec3f at;
    Vec3f up;
    u8 pad4C[0x160 - 0x4C];
    u32 flags;
} View;
void View_LookAt(View *view, Vec3f *eye, Vec3f *at, Vec3f *up) {
    if (eye->x == at->x && eye->z == at->z) {
        eye->z += D_801D6930;
        up->z = 0.0f;
        up->x = 0.0f;
        up->y = 1.0f;
    }
    view->eye = *eye;
    view->at = *at;
    view->up = *up;
    view->flags |= 1;
}
