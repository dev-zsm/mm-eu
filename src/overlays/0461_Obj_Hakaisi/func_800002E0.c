// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B14460(ObjHakaisi* this, PlayState* play) {
    s16 sp26 = BINANG_SUB(this->dyna.actor.shape.rot.y, this->dyna.actor.yawTowardsPlayer);

    if (Actor_TalkOfferAccepted(&this->dyna.actor, &play->state)) {
        ref_func_80B14510(this);
    } else if (this->dyna.actor.textId != 0) {
        if (ABS_ALT(sp26) < 0x2000) {
            Actor_OfferTalk(&this->dyna.actor, play, 100.0f);
        }
    }

    if (this->unk_198 == 1) {
        ref_func_80B14558(this);
    }
}
