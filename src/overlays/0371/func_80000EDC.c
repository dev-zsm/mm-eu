// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80000EDC(EnTrt* this, PlayState* play) {
    u8 talkState = Message_GetState(&play->msgCtx);

    if (talkState == TEXT_STATE_EVENT) {
        if (Message_ShouldAdvance(play)) {
            EnTrt_EndInteraction(play, this);
        }
    } else if (talkState == TEXT_STATE_DONE) {
        if (Message_ShouldAdvance(play)) {
            EnTrt_EndInteraction(play, this);
        }
    }
}
