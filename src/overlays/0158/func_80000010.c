// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_okarina_tag.h"

void EnOkarinaTag_Init(Actor* thisx, PlayState* play) {
    EnOkarinaTag* this = (EnOkarinaTag*)thisx;
    f32 zRot = 0.0f;
    s32 i = 0;

    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    this->unk148 = ENOKARINATAG_GET_F800(thisx);
    this->unk14A = ENOKARINATAG_GET_780(thisx);
    this->switchFlag = ENOKARINATAG_GET_SWITCH_FLAG(thisx);
    if (this->actor.world.rot.z > 0) {
        zRot = this->actor.world.rot.z;
        while (zRot > 10.0f) {
            zRot -= 10.0f;
            i++;
        }
    }
    this->unk154 = zRot * 50.0f;
    this->unk158 = i * 50.0f;
    if (this->switchFlag == ENOKARINATAG_SWITCH_FLAG_NONE) {
        this->switchFlag = SWITCH_FLAG_NONE;
    }
    if (this->unk14A == 0xF) {
        this->unk14A = -1;
    }
    this->actor.attentionRangeType = ATTENTION_RANGE_1;
    this->actionFunc = ref_func_8093E518;
}
