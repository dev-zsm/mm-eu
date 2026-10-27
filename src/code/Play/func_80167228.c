#include "types.h"

typedef struct {
    u8 pad0[0x81F];
    u8 r;
    u8 g;
    u8 b;
    s16 near;
    s16 far;
} Play;

extern void Gfx_SetFogWithSync(s32 a0, s32 r, s32 g, s32 b, s32 z, s32 n, s32 f);

void Play_SetFog(Play *play, s32 gfx) {
    s32 f = play->far * 0.078125f;
    s32 g;

    if (f < 1001) {
        g = 1000;
    } else {
        g = f;
    }
    Gfx_SetFogWithSync(gfx, play->r, play->g, play->b, 0, play->near, g);
}
