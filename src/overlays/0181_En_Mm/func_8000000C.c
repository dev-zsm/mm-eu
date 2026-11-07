// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mm.h"

void ref_func_80965BBC(EnMm* this) {
    EnMm_SetupAction(this, ref_func_8096611C);
    this->actor.room = -1;
    if (this->actor.parent->id == ACTOR_PLAYER) {
        gSaveContext.unk_1014 = 1;
    }
}
