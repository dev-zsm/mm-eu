// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ocarinalift.h"

void ref_func_80AC99D4(ObjOcarinalift* this, PlayState* play) {
    if (!DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        ref_func_80AC94C0(this, this->unk168);
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        if ((OBJOCARINALIFT_GET_C(&this->dyna.actor) == OBJOCARINALIFT_PARAM_1) &&
            (this->unk168 == OBJOCARINALIFT_GET_1F(&this->dyna.actor))) {
            ref_func_80AC9AB8(this);
        } else {
            ref_func_80AC96B4(this);
        }
    }
}
