// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_801EC678[];

void CutsceneManager_Queue(s16 csId) {
    if (csId >= 0) {
        D_801EC678[csId >> 3] |= 1 << (csId & 7);
    }
}
