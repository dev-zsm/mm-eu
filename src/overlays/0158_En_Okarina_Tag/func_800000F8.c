// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_okarina_tag.h"

void ref_func_8093E518(EnOkarinaTag* this, PlayState* play) {
    f32 xzRange;
    f32 yRange;
    s16 yDiff;
    u16 var_v1;

    if (this->switchFlag > SWITCH_FLAG_NONE) {
        if (this->unk148 == 0) {
            if (Flags_GetSwitch(play, this->switchFlag)) {
                return;
            }
        }
        if (this->unk148 == 1) {
            if (!Flags_GetSwitch(play, this->switchFlag)) {
                return;
            }
        }
    }
    var_v1 = this->unk14A;
    if (var_v1 == 6) {
        var_v1 = 0xA;
        if (!gSaveContext.save.saveInfo.scarecrowSpawnSongSet) {
            return;
        }
    }
    if (this->unk14A == -1) {
        var_v1 = 0;
    }
    if (Actor_OcarinaInteractionAccepted(&this->actor, &play->state)) {
        Message_DisplayOcarinaStaff(play, OCARINA_ACTION_CHECK_HEALING + var_v1);
        this->actionFunc = ref_func_8093E68C;
    } else {
        yDiff = ABS_ALT((s16)(this->actor.yawTowardsPlayer - this->actor.world.rot.y));
        if (yDiff >= 0x4300) {
            this->unk150 = 0;
            return;
        }
        xzRange = this->unk154;
        this->unk150 = 1;
        if (xzRange == 0.0f) {
            xzRange = 50000.0f;
        }
        yRange = this->unk158;
        if (yRange == 0.0f) {
            yRange = 50000.0f;
        }
        Actor_OfferOcarinaInteraction(&this->actor, play, xzRange, yRange);
    }
}
