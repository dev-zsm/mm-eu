// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_kibako2.h"

void ObjKibako2_Update(Actor* thisx, PlayState* play) {
    ObjKibako2* this = (ObjKibako2*)thisx;

    if (this->unk_1AC != 0) {
        play->actorCtx.flags |= ACTORCTX_FLAG_3;
    }

    if (this->skulltulaNoiseTimer >= 0) {
        if (this->skulltulaNoiseTimer == 0) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EN_STALGOLD_ROLL);
            if (Rand_ZeroOne() < 0.1f) {
                this->skulltulaNoiseTimer = Rand_S16Offset(40, 80);
            } else {
                this->skulltulaNoiseTimer = 8;
            }
        } else {
            this->skulltulaNoiseTimer--;
        }
    }
    this->actionFunc(this, play);
}
