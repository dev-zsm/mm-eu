// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mu_pict.h"

void ref_func_80C06B70(ObjMuPict* this, PlayState* play) {
    s16 yawDiff = this->actor.yawTowardsPlayer - this->actor.world.rot.y;

    if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        if (this->actor.csId <= CS_ID_NONE) {
            ref_func_80C06DC8(this, play);
            ref_func_80C06CC4(this);
        } else {
            if (CutsceneManager_GetCurrentCsId() == CS_ID_GLOBAL_TALK) {
                CutsceneManager_Stop(CS_ID_GLOBAL_TALK);
            }
            CutsceneManager_Queue(this->actor.csId);
            ref_func_80C06DC8(this, play);
            ref_func_80C06C54(this);
        }
    } else if (ABS_ALT(yawDiff) < 0x2AAA) {
        Actor_OfferTalk(&this->actor, play, 80.0f);
    }
}
