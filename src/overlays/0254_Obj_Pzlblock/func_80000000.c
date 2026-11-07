// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_pzlblock.h"

bool ref_func_809A33E0(ObjPzlblock* this, PlayState* play, s16 arg2) {
    return !DynaPolyActor_ValidateMove(play, &this->dyna, 30, arg2, 1) ||
           !DynaPolyActor_ValidateMove(play, &this->dyna, 30, arg2, 28);
}
