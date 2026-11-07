// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tanron6.h"

void EnTanron6_Init(Actor* thisx, PlayState* play) {
    EnTanron6* this = (EnTanron6*)thisx;

    this->actor.colChkInfo.mass = 10;
    ActorShape_Init(&this->actor.shape, 0, ActorShadow_DrawCircle, 19.0f);
    this->actor.colChkInfo.health = 1;
    this->actor.colChkInfo.damageTable = &sDamageTable;
    this->actor.attentionRangeType = ATTENTION_RANGE_6;
    EnTanron6_DoNothing(this);
}
