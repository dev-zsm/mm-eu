// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_TestItemSelected), score 2.00 (2 differ, size +0)
#include "generated/mm/z_en_trt.h"

bool func_8000009C(PlayState* play) {
    MessageContext* msgCtx = &play->msgCtx;

    if ((msgCtx->textboxEndType == TEXTBOX_ENDTYPE_TWO_CHOICE) ||
        (msgCtx->textboxEndType == TEXTBOX_ENDTYPE_THREE_CHOICE)) {
        return CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_A);
    }
    return CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_A) ||
           CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_B) ||
           CHECK_BTN_ALL(CONTROLLER1(&play->state)->press.button, BTN_CUP);
}
