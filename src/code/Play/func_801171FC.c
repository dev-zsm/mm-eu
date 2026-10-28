#include "types.h"

typedef struct { f32 x, y, z; } V3;
typedef struct { u8 pad0[0x200]; s32 a; s32 b; s32 c; s32 d; } View2;
void View_LookAt(View2 *v, V3 *eye, V3 *at, V3 *up);
void View_SetViewport(View2 *v, void *p);
void View_SetPerspective(View2 *v, f32 a, f32 b, f32 c);
void View_ApplyPerspectiveToOverlay(View2 *v);

void func_801171FC(u8 *play, s32 a, s32 b, s32 c, s32 d) {
    View2 *view = (View2 *)&play[0x169E8];
    V3 eye;
    V3 at;
    V3 up;

    eye.z = 0.0f;
    eye.y = 0.0f;
    eye.x = 0.0f;
    at.z = -1.0f;
    at.y = 0.0f;
    at.x = 0.0f;
    up.z = 0.0f;
    up.y = 1.0f;
    up.x = 0.0f;
    View_LookAt(view, &eye, &at, &up);
    view->a = a;
    view->b = b;
    view->c = c;
    view->d = d;
    View_SetViewport(view, &view->a);
    View_SetPerspective(view, 60.0f, 10.0f, 60.0f);
    View_ApplyPerspectiveToOverlay(view);
}
