#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ s32 unk10;
    /* 0x14 */ u8 pad14[4];
    /* 0x18 */ s32 unk18;
} PreRender;

extern void PreRender_FetchFbufCoverage(PreRender *prerender, void *gfx);
extern void PreRender_CoverageRgba16ToI8(PreRender *prerender, void *gfx, s32 arg2, s32 arg3);

void PreRender_DrawCoverage(PreRender *prerender, void *gfx) {
    PreRender_FetchFbufCoverage(prerender, gfx);
    if (prerender->unk18 != 0) {
        PreRender_CoverageRgba16ToI8(prerender, gfx, prerender->unk10, prerender->unk18);
    }
}
