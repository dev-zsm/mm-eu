// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"

extern f32 D_801D3DD4;
extern f32 D_801D3DE0;
extern s8 D_801D3DE8;


void Audio_PlaySfx_IfNotInCutscene(u16 sfxId) {
    Audio_PlaySfx_IfNotInCutsceneImpl(sfxId, &D_801D3DD4, 4, &D_801D3DE0, &D_801D3DE0, &D_801D3DE8);
}
