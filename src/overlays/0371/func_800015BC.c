// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_800015BC(PlayState* play, EnTrt* this) {
    EnGirlA* item = this->items[this->cursorIndex];
    EnGirlA* item2;

    switch (item->canBuyFunc(play, item)) {
        case CANBUY_RESULT_SUCCESS_1:
            if (this->cutsceneState == ENTRT_CUTSCENESTATE_PLAYING) {
            CutsceneManager_Stop(this->csId);
            this->cutsceneState = ENTRT_CUTSCENESTATE_STOPPED;
            }
            Audio_PlaySfx_MessageDecide();
            item2 = this->items[this->cursorIndex];
            item2->buyFanfareFunc(play, item2);
            EnTrt_SetupBuyItemWithFanfare(play, this);
            this->drawCursor = 0;
            this->shopItemSelectedTween = 0.0f;
            item->boughtFunc(play, item);
            break;

        case CANBUY_RESULT_SUCCESS_2:
            Audio_PlaySfx_MessageDecide();
            item->buyFunc(play, item);
            EnTrt_SetupCanBuy(play, this, 0x848);
            this->drawCursor = 0;
            this->shopItemSelectedTween = 0.0f;
            item->boughtFunc(play, item);
            break;

        case CANBUY_RESULT_NO_ROOM:
            Audio_PlaySfx(NA_SE_SY_ERROR);
            EnTrt_SetupCannotBuy(play, this, 0x641);
            break;

        case CANBUY_RESULT_NEED_EMPTY_BOTTLE:
            Audio_PlaySfx(NA_SE_SY_ERROR);
            EnTrt_SetupCannotBuy(play, this, 0x846);
            break;

        case CANBUY_RESULT_NEED_RUPEES:
            Audio_PlaySfx(NA_SE_SY_ERROR);
            EnTrt_SetupCannotBuy(play, this, 0x847);
            break;

        case CANBUY_RESULT_CANNOT_GET_NOW:
            Audio_PlaySfx(NA_SE_SY_ERROR);
            EnTrt_SetupCannotBuy(play, this, 0x643);
            break;

        default:
            break;
    }
}
