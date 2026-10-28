#include "types.h"

typedef struct { s32 x; s32 y; s32 z; } V3i;
typedef struct { u8 id; u8 b; u16 c; V3i pos; V3i out; } SoundSrc;
void AudioSfx_StopByPos(void *a);
void SkinMatrix_Vec3fMtxFMultXYZ(s32 a, void *b, void *c);
void Audio_PlaySfx_AtPos(void *a, u16 b);

void SoundSource_Add(s32 play, V3i *pos, s32 id, u16 sfxId, s32 b) {
    s32 minId = 0xFFFF;
    SoundSrc *oldest = NULL;
    SoundSrc *src = (SoundSrc *)(play + 0x1F78);
    s32 i;
    for (i = 0; i < 0x10; i++, src++) {
        u8 cur = src->id;
        if (cur == 0) {
            break;
        }
        if (cur < minId) {
            minId = cur;
            oldest = src;
        }
    }
    if (i >= 0x10) {
        AudioSfx_StopByPos(&oldest->out);
        src = oldest;
    }
    src->pos = *pos;
    src->id = id;
    src->b = b;
    src->c = sfxId;
    SkinMatrix_Vec3fMtxFMultXYZ(play + 0x187B0, &src->pos, &src->out);
    Audio_PlaySfx_AtPos(&src->out, sfxId);
}
