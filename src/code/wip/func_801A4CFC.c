#include "types.h"

extern u8 D_801CF010;
extern u8 D_801CF018;
extern u8 D_801D3DD4;
extern u8 D_801D3DE0;
extern u8 D_801D3DE8;
extern void AudioSfx_StopById(s32);
extern void AudioSfx_PlaySfx(s32, void *, s32, void *, void *);

void Audio_SetBaseFilter(u8 filter) {
    if (D_801CF010 != filter) {
        if (filter == 0) {
            AudioSfx_StopById(0x86B);
        } else if (D_801CF010 == 0) {
            AudioSfx_PlaySfx(0x86B, &D_801D3DD4, 4, &D_801D3DE0, &D_801D3DE8);
        }
    }
    D_801CF010 = filter;
    D_801CF018 = filter;
}
