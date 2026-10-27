#include "types.h"

extern s32 D_801C9E30;
extern s32 D_801C9E34;

extern void Actor_GetScreenPos(void *a, void *b, s16 *x, s16 *y);

s32 Attention_ActorOnScreen(void *a, void *b) {
    s16 x;
    s16 y;

    Actor_GetScreenPos(a, b, &x, &y);
    return x >= -0x13 && x < D_801C9E30 + 0x14 && y >= -0x9F && y < D_801C9E34 + 0xA0;
}
