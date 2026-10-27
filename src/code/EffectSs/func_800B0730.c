#include "types.h"

typedef struct {
    u8 pad0[0x5A];
    u16 flags;
} EffectSs;

extern void AudioSfx_StopByPos(void *a0);
extern void EffectSs_Reset(EffectSs *effect);

void EffectSs_Delete(EffectSs *effect) {
    if (effect->flags & 2) {
        AudioSfx_StopByPos(effect);
    }
    if (effect->flags & 4) {
        AudioSfx_StopByPos((u8 *)effect + 0x2C);
    }
    EffectSs_Reset(effect);
}
