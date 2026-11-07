// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

void ObjDriftice_Update(Actor* thisx, PlayState* play) {
    ObjDriftice* this = (ObjDriftice*)thisx;

    if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        if (this->unk_248 < 0) {
            this->unk_248 = 1;
        } else {
            this->unk_248++;
        }
    } else {
        if (this->unk_248 > 0) {
            this->unk_248 = -1;
        } else {
            this->unk_248--;
        }
    }

    this->dyna.actor.shape.rot.y += this->unk_244;

    this->actionFunc(this, play);

    if (OBJDRIFTICE_GET_ROT(&this->dyna.actor) && (this->dyna.actor.flags & ACTOR_FLAG_INSIDE_CULLING_VOLUME)) {
        ref_func_80A66E30(&this->unk_170, this);
    }
}
