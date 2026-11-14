// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_HasPlayerSelectedItem), score 0.00 (0 differ, size +0)
#include "generated/mm/z_en_trt.h"

s32 func_800012BC(PlayState* play, EnTrt* this, Input* input) {
    EnGirlA* item = this->items[this->cursorIndex];

    if (EnTrt_TestEndInteraction(this, play, input)) {
        return true;
    }
    if (EnTrt_TestItemSelected(play)) {
        if ((item->actor.params != SI_POTION_BLUE) || (this->flags & ENTRT_GIVEN_MUSHROOM)) {
            this->prevActionFunc = this->actionFunc;
            Message_ContinueTextbox(play, EnTrt_GetItemChoiceTextId(this));
            Audio_PlaySfx(NA_SE_SY_DECIDE);
            this->stickLeftPrompt.isEnabled = false;
            this->stickRightPrompt.isEnabled = false;
            this->drawCursor = 0;
            this->actionFunc = EnTrt_SelectItem;
        } else {
            Audio_PlaySfx(NA_SE_SY_ERROR);
        }
        return true;
    }
    return false;
}
