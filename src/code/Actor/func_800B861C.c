// FLAGS: -O2 -g3 -mips2 -Wab,-r4300_mul
#include "types.h"
typedef struct { f32 x, y, z; } V;
void Actor_GetProjectedPos(s32, void *, V *, f32 *);
void Actor_GetScreenPos(s32 a0, u8 *a, s16 *x, s16 *y) {
    V p;
    f32 w;
    Actor_GetProjectedPos(a0, a + 0x3C, &p, &w);
    *x = (s32)((p.x * w * 160.0f) + 160.0f);
    *y = (s32)((p.y * w * -120.0f) + 120.0f);
}
