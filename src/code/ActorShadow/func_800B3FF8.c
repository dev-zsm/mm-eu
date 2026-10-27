#include "types.h"

extern u8 D_4076BC0;
extern u8 D_801AF7B0;

void ActorShadow_Draw();

void ActorShadow_DrawWhiteCircle(s32 a0, s32 a1, s32 a2) {
    ActorShadow_Draw(a0, a1, a2, &D_4076BC0, &D_801AF7B0);
}
