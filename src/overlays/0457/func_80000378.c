// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_onpuman.h"

void ref_func_80B121D8(EnOnpuman* this, PlayState* play) {
    s16 yaw;

    if (Actor_OcarinaInteractionAccepted(&this->actor, &play->state)) {
        this->actionFunc = ref_func_80B1202C;
        Message_StartTextbox(play, 0x8D4, NULL);
        this->unk_2A0 = ref_func_80B11F44(play);
    } else if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        this->actionFunc = ref_func_80B1217C;
    } else {
        yaw = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
        if (this->actor.xzDistToPlayer < 200.0f) {
            if (ABS_ALT(yaw) <= 0x4300) {
                this->actor.textId = 0x8D3;
                Actor_OfferTalk(&this->actor, play, 100.0f);
                Actor_OfferOcarinaInteraction(&this->actor, play, 100.0f, 100.0f);
            }
        }
    }
}
