// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_talk.h"

void EnTalk_Init(Actor* thisx, PlayState* play) {
    EnTalk* this = (EnTalk*)thisx;
    s8 attentionRangeType = ENTALK_GET_ATTENTION_RANGE_TYPE(&this->actor);

    if ((attentionRangeType >= ATTENTION_RANGE_0) && (attentionRangeType < ATTENTION_RANGE_7)) {
        this->actor.attentionRangeType = attentionRangeType;
    }

    Actor_SetScale(&this->actor, 1.0f);
    this->actionFunc = ref_func_80BDE090;
    this->actor.textId = ENTALK_GET_TEXT_ID(&this->actor);
}
