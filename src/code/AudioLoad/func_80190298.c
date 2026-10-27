#include "types.h"

extern u8 D_801F84B0[];

void AudioLoad_SetSeqLoadStatus(s32 arg0, s32 arg1) {
    if (arg0 != 0xFF) {
        if (D_801F84B0[arg0 + 0x43C8] != 5) {
            D_801F84B0[arg0 + 0x43C8] = arg1;
        }
    }
}
