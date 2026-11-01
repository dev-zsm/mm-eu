// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u32 D_801FCBD0;
extern u8 D_801D3DA4;
extern u8 D_801D3DA0;

void AudioSfx_ProcessRequests(void) {
    if (D_801FCBD0 >> 31) {
        while (D_801D3DA0 != D_801D3DA4) {
            AudioSfx_ProcessRequest();
            D_801D3DA4++;
        }
    }
}
