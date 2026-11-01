// FLAGS: -O2 -g0
#include "types.h"
#include "code_funcs.h"

extern u8 D_801CEFDC;


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
