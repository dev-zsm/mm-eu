// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct { u8 pad[0x3C]; f32 pos[3]; } Actor;
void Actor_GetProjectedPos(void *, f32 *, f32 *, f32 *);
s32 Actor_OnScreen(void *play, Actor *actor) {
    f32 xy[3];
    f32 w;
    f32 pad[3]; // frame padding to match the original stack layout
    Actor_GetProjectedPos(play, actor->pos, xy, &w);
    return (-1.0f <= xy[0] * w) && (xy[0] * w <= 1.0f) && (-1.0f <= xy[1] * w) && (xy[1] * w <= 1.0f);
}
