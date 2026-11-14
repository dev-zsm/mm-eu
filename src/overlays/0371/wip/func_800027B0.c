// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_CanBuy), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_trt.h"

void func_800027B0(EnTrt* this, PlayState* play) {
    EnGirlA* item;

    if ((Message_GetState(&play->msgCtx) == TEXT_STATE_EVENT) && Message_ShouldAdvance(play)) {
        this->shopItemSelectedTween = 0.0f;
        EnTrt_ResetItemPosition(this);
        item = this->items[this->cursorIndex];
        item->restockFunc(play, item);
        this->actionFunc = this->prevActionFunc;
        Message_ContinueTextbox(play, EnTrt_GetItemTextId(this));
    }
}
