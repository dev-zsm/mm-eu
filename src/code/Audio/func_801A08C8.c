// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"
typedef struct { u8 pad0[4]; f32 f; } Ent;
extern u8 D_801D3DE8[];
Ent *AudioSfx_AddSfxSetting(void *pos, s32 sfx);
void Audio_PlaySfx_AtPosWithFreqAndVolume(void *pos, s32 sfx, f32 freq, s32 *vol) {
    Ent *e = AudioSfx_AddSfxSetting(pos, sfx);
    f32 *p;
    if (e != 0) {
        p = &e->f;
        if (freq < 0.75f) {
            *p = (freq / 0.75f) * 0.25f + 0.5f;
        } else {
            *p = freq;
        }
        if (*p > 0.5f) {
            AudioSfx_PlaySfx(sfx, pos, 4, &e->f, vol, D_801D3DE8);
        }
    }
}
