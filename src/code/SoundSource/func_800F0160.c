#include "types.h"
typedef struct { u8 life; u8 f1; u16 h2; u8 pad4[0xC]; u8 tail[0xC]; } Src;
typedef struct { u8 pad0[0x1F78]; Src src[16]; u8 pad1[0x187B0 - 0x1F78 - 16 * sizeof(Src)]; u8 g[1]; } Ctx;
void AudioSfx_StopByPos(void *a);
void SkinMatrix_Vec3fMtxFMultXYZ(void *a, void *b, void *c);
void Audio_PlaySfx_AtPos(void *a, u16 b);
#define DECR(x) ((x) == 0 ? 0 : --(x))
void SoundSource_UpdateAll(Ctx *c) {
    s32 i;
    Src *s = c->src;
    for (i = 0; i != 16; i++, s++) {
        if (s->life != 0) {
            if (DECR(s->life) == 0) {
                AudioSfx_StopByPos(s->tail);
            } else {
                SkinMatrix_Vec3fMtxFMultXYZ((u8 *)c + 0x187B0, (u8 *)s + 4, s->tail);
                if (s->f1 != 0) {
                    Audio_PlaySfx_AtPos(s->tail, s->h2);
                }
            }
        }
    }
}
