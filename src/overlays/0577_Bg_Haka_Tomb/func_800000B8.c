// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_haka_tomb.h"

s32 ref_func_80BD6638(s16* csId, s16* csIdList, s32 numCutscenes) {
    s32 pad;
    s32 retVal = false;
    s32 i;

    *csId = CutsceneManager_GetCurrentCsId();
    if (*csId > CS_ID_NONE) {
        for (i = 0; i < numCutscenes; i++) {
            if (*csId == csIdList[i]) {
                retVal = true;
                break;
            }
        }
    }

    return retVal;
}
