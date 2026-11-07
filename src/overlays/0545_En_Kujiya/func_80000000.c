// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kujiya.h"

void EnKujiya_Init(Actor* thisx, PlayState* play) {
    EnKujiya* this = (EnKujiya*)thisx;

    Actor_SetScale(&this->actor, 0.1f);

    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    this->actor.attentionRangeType = ATTENTION_RANGE_6;

    this->actor.focus.pos = this->actor.world.pos;
    this->actor.focus.pos.y += 30.0f;

    if (EnKujiya_CheckBoughtTicket() && (CURRENT_TIME >= CLOCK_TIME(6, 0)) && (CURRENT_TIME < CLOCK_TIME(18, 0))) {
        this->actor.shape.rot.y = 0;
    } else {
        this->actor.shape.rot.y = 0x7555;
    }
    EnKujiya_SetupWait(this);
}
