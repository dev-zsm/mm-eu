// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fbdemo_circle.h"

void TransitionCircle_LoadAndSetTexture(Gfx** gfxP, void const* texture, s32 fmt, s32 arg3, s32 masks, s32 maskt,
                                        f32 arg6) {
    Gfx* gfx = *gfxP;
    s32 xh = gCfbWidth;
    s32 yh = gCfbHeight;
    s32 width = 1 << masks;
    s32 height = 1 << maskt;
    f32 s;
    f32 t;
    s32 dtdy;
    s32 dsdx;

    gDPLoadTextureBlock_4b(gfx++, texture, fmt, width, height, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP,
                           masks, maskt, G_TX_NOLOD, G_TX_NOLOD);
    gDPSetTileSize(gfx++, G_TX_RENDERTILE, ((SCREEN_WIDTH / 2) - width) << 2, ((SCREEN_HEIGHT / 2) - height) << 2,
                   ((SCREEN_WIDTH / 2) + (width - 1)) << 2, ((SCREEN_HEIGHT / 2) + (height - 1)) << 2);

    s = ((1.0f - (1.0f / arg6)) * (SCREEN_WIDTH / 2)) + 70.0f;
    t = ((1.0f - (1.0f / arg6)) * (SCREEN_HEIGHT / 2)) + 50.0f;

    if (s < -1023.0f) {
        s = -1023.0f;
    }
    if (t < -1023.0f) {
        t = -1023.0f;
    }

    if ((s <= -1023.0f) || (t <= -1023.0f)) {
        dsdx = 0;
        dtdy = 0;
    } else {
        dsdx = ((SCREEN_WIDTH - (2.0f * s)) / gScreenWidth) * (1 << 10);
        dtdy = ((SCREEN_HEIGHT - (2.0f * t)) / gScreenHeight) * (1 << 10);
    }

    gSPTextureRectangle(gfx++, 0, 0, xh << 2, yh << 2, G_TX_RENDERTILE, (s32)(s * (1 << 5)), (s32)(t * (1 << 5)), dsdx,
                        dtdy);
    gDPPipeSync(gfx++);

    *gfxP = gfx;
}
