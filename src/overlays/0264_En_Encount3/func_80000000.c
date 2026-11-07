// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_encount3.h"

void EnEncount3_Init(Actor* thisx, PlayState* play) {
    EnEncount3* this = (EnEncount3*)thisx;

    this->unk14A = ENCOUNT3_GET_SPAWN_INDEX(thisx);
    this->childParams = ENCOUNT3_GET_PARAM_F80(thisx);
    this->switchFlag = ENCOUNT3_GET_SWITCH_FLAG(thisx);
    this->csId = this->actor.csId;
    this->unk16C = ENCOUNT3_GET_ROTZ(thisx) * 10.0f;
    if (this->unk16C < 10.0f) {
        this->unk16C = 10.0f;
    } else if (this->unk16C > 1000.0f) {
        this->unk16C = 1000.0f;
    }
    if (this->switchFlag == ENCOUNT3_SWITCH_FLAG_NONE) {
        this->switchFlag = SWITCH_FLAG_NONE;
    }
    if ((this->switchFlag > SWITCH_FLAG_NONE) && Flags_GetSwitch(play, this->switchFlag)) {
        Actor_Kill(&this->actor);
    }
    this->actor.flags |= ACTOR_FLAG_LOCK_ON_DISABLED;
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    ref_func_809AD058(this);
}
