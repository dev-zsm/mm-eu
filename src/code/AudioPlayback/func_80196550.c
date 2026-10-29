// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[4];
    u16 numSfx;
    u8 pad6[0xA];
    u32 sfx;
} Font;

extern struct {
    u8 pad0[0x2868];
    Font *fonts;
    u8 pad286C[0x134];
    s32 error;
} D_801F84B0;

extern s32 AudioLoad_IsFontLoadComplete(s32);

s32 *AudioPlayback_GetSoundEffect(s32 fontId, s32 id) {
    s32 *sfx; u32 base; Font *font;

    if (fontId == 0xFF) {
        return NULL;
    }
    if (AudioLoad_IsFontLoadComplete(fontId) == 0) {
        D_801F84B0.error = fontId + 0x10000000;
        return NULL;
    }
    font = (Font *)((s32)D_801F84B0.fonts + fontId * 0x14);
    if (id >= font->numSfx) {
        D_801F84B0.error = (fontId << 8) + id + 0x04000000;
        return NULL;
    }
    base = font->sfx;
    sfx = (s32 *)((u32)base + (id << 3));
    if (base < 0x80000000) {
        return NULL;
    }
    if (sfx == NULL) {
        D_801F84B0.error = (fontId << 8) + id + 0x05000000;
    }
    if (*sfx == 0) {
        return NULL;
    }
    return sfx;
}
