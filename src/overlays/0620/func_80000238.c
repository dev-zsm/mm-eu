// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mu_pict.h"

void ref_func_80C06CD8(ObjMuPict* this, PlayState* play) {
    switch (Message_GetState(&play->msgCtx)) {
        case TEXT_STATE_NONE:
        case TEXT_STATE_NEXT:
        case TEXT_STATE_CLOSING:
        case TEXT_STATE_FADING:
        case TEXT_STATE_CHOICE:
            break;

        case TEXT_STATE_EVENT:
            ref_func_80C06E88(this, play);
            break;

        case TEXT_STATE_DONE:
            if (Message_ShouldAdvance(play)) {
                ref_func_80C06B5C(this);
                if (this->actor.csId > CS_ID_NONE) {
                    CutsceneManager_Stop(this->actor.csId);
                }
            }
            break;
    }
    Math_SmoothStepToS(&this->actor.parent->world.rot.y, this->actor.parent->yawTowardsPlayer, 0xA, 0x71C, 0xB6);
    this->actor.parent->shape.rot.y = this->actor.parent->world.rot.y;
}
