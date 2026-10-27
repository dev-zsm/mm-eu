// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern f32 D_801D1504[3];

void Audio_PlaySfx_AtPos(f32 *pos, u16 sfxId);

void Audio_PlaySfx_AtFixedPos(f32 *pos, u16 sfxId) {
    s32 i;

    for (i = 0; i < 3; i++) {
        D_801D1504[i] = pos[i];
    }
    Audio_PlaySfx_AtPos(D_801D1504, sfxId);
}
