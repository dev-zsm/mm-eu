// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80000A78(EnTrt* this, PlayState* play) {
    if ((Message_GetState(&play->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(play)) {
        switch (this->textId) {
            case 0x886:
                this->textId = 0x887;
                Message_ContinueTextbox(play, this->textId);
                break;

            case 0x887:
            case 0x88B:
                EnTrt_EndInteraction(play, this);
                break;

            default:
                break;
        }
    }
}
