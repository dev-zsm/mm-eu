// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hariko.h"

void ObjHariko_SetupBobHead(ObjHariko* this) {
    this->bobbleStep = 2730.0f;
    this->unk154 = 0;
    this->actionFunc = ObjHariko_BobHead;
}
