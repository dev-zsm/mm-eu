// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_tag.h"

MsgScript* DmTag_GetMsgScript(DmTag* this, PlayState* play) {
    s32 time;

    switch (this->unk_18E) {
        case 1:
            time = SCRIPT_TIME_NOW;
            if ((time >= SCRIPT_TIME(21, 30)) && (time < SCRIPT_TIME(23, 0))) {
                if (gSaveContext.save.day == 2) {
                    this->msgScriptCallback = ref_func_80C227E8;
                    return ref_D_80C22BF0;
                }
            }
            return ref_D_80C22C30;

        case 2:
            this->msgScriptCallback = ref_func_80C224D8;
            return ref_D_80C22BFC;

        default:
            break;
    }

    return NULL;
}
