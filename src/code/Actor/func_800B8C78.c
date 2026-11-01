// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SurfaceType_GetSfxOffset(void *, s32, u8, void *);
void Audio_PlaySfx_AtPos(void *, s32);

void Actor_PlaySfx_SurfaceBomb(s32 arg0, u8 *arg1) {
    s32 v1;
    if (*(u16 *)(arg1 + 0x90) & 0x20) {
        if (*(f32 *)(arg1 + 0x8C) < 20.0f) { v1 = 4; } else { v1 = 5; }
    } else {
        v1 = SurfaceType_GetSfxOffset((void *)(arg0 + 0x830), *(s32 *)(arg1 + 0x80), *(u8 *)(arg1 + 0x85), arg1);
    }
    Audio_PlaySfx_AtPos(arg1 + 0xEC, 0x282F);
    Audio_PlaySfx_AtPos(arg1 + 0xEC, (v1 + 0x800) & 0xFFFF);
}
