// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bell.h"

void ObjBell_Update(Actor* thisx, PlayState* play) {
    ObjBell* this = (ObjBell*)thisx;

    if (this->unk_214 != 0) {
        this->unk_214--;
    }
    ref_func_80A357A8(this, play);
    ref_func_80A356D8(this);
    ref_func_80A358FC(this, play);
}
