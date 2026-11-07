// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_driftice.h"

void ref_func_80A67450(ObjDriftice* this, PlayState* play) {
    if (this->unk_248 < 0) {
        ref_func_80A66570(this, this->unk_164);
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        ref_func_80A671CC(this);
    }
}
