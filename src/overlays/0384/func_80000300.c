// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char05.h"

void DmChar05_Init(Actor* thisx, PlayState* play) {
    DmChar05* this = (DmChar05*)thisx;

    this->animIndex = DMCHAR05_ANIM_0;
    this->unk_18E = 0;
    this->unk_19C = 0;
    this->unk_1A0 = 0;
    this->unk_1A4 = 0;
    this->unk_1A8 = 0;
    this->unk_1AC = 100;
    this->unk_1B0 = 1000;
    this->unk_1B4 = 0;

    switch (DMCHAR05_GET(&this->actor)) {
        case DMCHAR05_0:
            ref_func_80AAC63C(thisx, play);
            break;

        case DMCHAR05_1:
            ref_func_80AAC6E4(thisx, play);
            break;

        case DMCHAR05_2:
            ref_func_80AAC770(thisx, play);
            break;

        case DMCHAR05_3:
            ref_func_80AAC7FC(thisx, play);
            break;

        case DMCHAR05_4:
            ref_func_80AAC888(thisx, play);
            break;

        case DMCHAR05_5:
        case DMCHAR05_6:
        case DMCHAR05_7:
        case DMCHAR05_8:
        case DMCHAR05_9:
        case DMCHAR05_10:
        case DMCHAR05_11:
        case DMCHAR05_12:
            this->actionFunc = ref_func_80AACBE4;
            break;
    }
    Actor_SetScale(&this->actor, 0.01f);
}
