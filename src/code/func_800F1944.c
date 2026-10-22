// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801EC678[];

void CutsceneManager_Queue(s16 arg0) {
    if (arg0 >= 0) {
        D_801EC678[arg0 >> 3] |= 1 << (arg0 & 7);
    }
}
