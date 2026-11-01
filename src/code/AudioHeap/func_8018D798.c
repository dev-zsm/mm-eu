// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"

void AudioHeap_ClearFilter(s16 *filter) {
    s32 i;

    for (i = 0; i < 8; i++) {
        filter[i] = 0;
    }
}
