// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern u8 D_801D3E08;
extern s8 D_801D3DCC;
extern s32 func_80194AEC(void);
extern void AudioThread_QueueCmdS8(s32, s32);
extern void func_801A5C68(void);

u8 AudioSeq_UpdateAudioHeapReset(void) {
    u8 state = D_801D3E08;

    if (state != 0) {
        if (state == 1) {
            if (func_80194AEC() == 1) {
                D_801D3E08 = 0;
                AudioThread_QueueCmdS8(0x46020000, D_801D3DCC);
                func_801A5C68();
            }
            state = D_801D3E08;
        } else if (state == 2) {
            while (func_80194AEC() != 1) {
            }
            D_801D3E08 = 0;
            AudioThread_QueueCmdS8(0x46020000, D_801D3DCC);
            func_801A5C68();
            state = D_801D3E08;
        }
    }
    return state;
}
