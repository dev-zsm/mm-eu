#include "types.h"

typedef struct {
    u8 pad0[0xEC];
    u8 projectedPos[0x153 - 0xEC];
    u8 unk153;
} Player;

extern u8 D_801D3DE0[];
extern u8 D_801D3DE8[];

extern void Audio_PlaySfx_AtPosWithPresetLowFreqAndHighReverb(void *pos, u16 sfxId);
extern void AudioSfx_PlaySfx(u16 sfxId, void *pos, s32 token, void *freqScale, void *volume, void *reverbAdd);

void Player_PlaySfx(Player *this, u16 sfxId) {
    if (this->unk153 == 0x14) {
        Audio_PlaySfx_AtPosWithPresetLowFreqAndHighReverb(this->projectedPos, sfxId);
    } else {
        AudioSfx_PlaySfx(sfxId, this->projectedPos, 4, D_801D3DE0, D_801D3DE0, D_801D3DE8);
    }
}
