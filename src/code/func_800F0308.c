// FLAGS: -O2 -g3 -mips2
#include "types.h"

void SoundSource_Add(void *, void *, void *, u16, s32);

void SoundSource_PlaySfxAtFixedWorldPos(void *a0, void *a1, void *a2, u16 a3) {
    SoundSource_Add(a0, a1, a2, a3, 0);
}
