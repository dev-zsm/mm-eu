// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnTrt_FacingShopkeeperDialogResult), score 1.00 (1 differ, size +0)
#include "generated/mm/z_en_trt.h"

s32 func_80000F5C(EnTrt* this, PlayState* play) {
    switch (play->msgCtx.choiceIndex) {
        case 0:
            Audio_PlaySfx_MessageDecide();
            EnTrt_SetupTalkToShopkeeper(play, this);
            return true;

        case 1:
            Audio_PlaySfx_MessageCancel();
            EnTrt_EndInteraction(play, this);
            return true;

        default:
            return false;
    }
}
