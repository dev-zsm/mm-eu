#include "types.h"
typedef struct { s8 a, b, c, d; } Shrink;
extern Shrink *D_801EE3D4;
extern void Math_StepToIGet(s32 *, s32, s32);

void ShrinkWindow_Update(s32 div) {
    s32 step;
    s32 v;

    if (div == 3) {
        step = 10;
    } else {
        step = 30 / div;
    }
    v = D_801EE3D4->b;
    Math_StepToIGet(&v, D_801EE3D4->a, step);
    D_801EE3D4->b = v;
    v = D_801EE3D4->d;
    Math_StepToIGet(&v, D_801EE3D4->c, step);
    D_801EE3D4->d = v;
}
