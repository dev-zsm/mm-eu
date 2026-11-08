// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SurfaceType_GetSfxOffset(void *, s32, u8, void *);
void Audio_PlaySfx_AtPos(void *, s32);

void Actor_PlaySfx_SurfaceBomb(struct PlayState *play, struct Actor *actor) {
    s32 v1;
    if (*(u16 *)((u8 *)actor + 0x90) & 0x20) {
        if (*(f32 *)((u8 *)actor + 0x8C) < 20.0f) { v1 = 4; } else { v1 = 5; }
    } else {
        v1 = SurfaceType_GetSfxOffset((void *)((u8 *)play + 0x830), *(s32 *)((u8 *)actor + 0x80), *(u8 *)((u8 *)actor + 0x85), actor);
    }
    Audio_PlaySfx_AtPos((u8 *)actor + 0xEC, 0x282F);
    Audio_PlaySfx_AtPos((u8 *)actor + 0xEC, (v1 + 0x800) & 0xFFFF);
}
