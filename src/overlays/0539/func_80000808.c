// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_nozoki.h"

s32 ref_func_80BA2C28(ObjNozoki* this) {
    s32 i;
    s16 csId = this->csId;

    for (i = 0; i < 3; i++) {
        if (CutsceneManager_GetCurrentCsId() == csId) {
            return i;
        }
        csId = CutsceneManager_GetAdditionalCsId(csId);
    }

    return -1;
}
