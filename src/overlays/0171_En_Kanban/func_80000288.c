// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kanban.h"

void ref_func_80954BE8(EnKanban* this, PlayState* play) {
    s16 yaw;

    if (!this->msgFlag) {
        if (this->msgTimer == 0) {
            yaw = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;
            if (ABS_ALT(yaw) < 0x2800) {
                if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
                    this->msgFlag = true;
                } else {
                    Actor_OfferTalk(&this->actor, play, 68.0f);
                }
            }
        } else {
            this->msgTimer--;
        }
    } else if (Actor_TextboxIsClosing(&this->actor, play)) {
        this->msgFlag = false;
        this->msgTimer = 20;
    }
}
