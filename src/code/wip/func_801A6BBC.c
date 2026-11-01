#include "types.h"
typedef struct { u16 unk0; u8 unk2; u8 pad3; f32 unk4; s32 unk8; s32 unkC; s32 unk10; } Req;
extern u8 D_801D3DA0;
extern u8 D_801D3DA4;
extern Req D_801F6000[];
extern u8 D_801F74C4[];
void AudioSfx_PlaySfx(u16 sfxId, s32 pos, u8 token, s32 freqScale, s32 vol, s32 reverbAdd) {
    Req *r;
    u8 i;
    if (D_801F74C4[(sfxId >> 12) & 0xFF] == 0) {
        r = &D_801F6000[D_801D3DA0];
        for (i = D_801D3DA4; D_801D3DA0 != i; i++) {
            if (D_801F6000[i].unk8 == pos && D_801F6000[i].unk0 == sfxId) {
                return;
            }
        }
        r->unk0 = sfxId;
        r->unk8 = pos;
        r->unk2 = token;
        r->unkC = freqScale;
        r->unk10 = vol;
        *(s32 *)&r->unk4 = reverbAdd;
        D_801D3DA0++;
    }
}
