// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern s32 D_801CEF84;

extern void Audio_PlaySfx_AtPosWithVolume(void *pos, u16 sfxId, f32 volume);
extern void Audio_SetSfxVolumeTransition(s32 *volume, f32 target, u16 duration);

void Audio_PlaySfx_AtPosWithVolumeTransition(void *pos, u16 sfxId, u16 duration) {
    Audio_PlaySfx_AtPosWithVolume(pos, sfxId, 0);
    Audio_SetSfxVolumeTransition(&D_801CEF84, 1.0f, duration);
}
