// FLAGS: -O2 -g0
#include "types.h"

extern u8 D_801CEFDC;

extern void Audio_PlaySfx(s32 id);
extern void AudioThread_QueueCmdS32(u32 a, s32 b);

void Audio_PlaySfx_PauseMenuOpenOrClose(u8 flag) {
    D_801CEFDC = flag;
    if (flag != 0) {
        Audio_PlaySfx(0x4800);
        AudioThread_QueueCmdS32(0xF1FF0000, 0);
    } else {
        Audio_PlaySfx(0x4801);
        AudioThread_QueueCmdS32(0xF2FF0000, 0);
    }
}
