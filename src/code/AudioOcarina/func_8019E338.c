// FLAGS: -O2 -g0 -mips2
#include "types.h"

extern u8 D_801CF968;
extern u8 D_801CF96C;
extern u8 D_801CF970[];

extern void AudioOcarina_MemoryGameNextNote(void);

void AudioOcarina_MemoryGameInit(u8 difficulty) {
    u8 i;

    if (difficulty > 2) {
        difficulty = 2;
    }
    D_801CF968 = 0;
    D_801CF96C = D_801CF970[difficulty];

    for (i = 0; i < 3; i++) {
        AudioOcarina_MemoryGameNextNote();
    }
}
