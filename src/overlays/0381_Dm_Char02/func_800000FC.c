// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_char02.h"

void DmChar02_PlaySfxForCutscenes(DmChar02* this, PlayState* play) {
    if ((play->csCtx.state != CS_STATE_IDLE) && (play->sceneId == SCENE_OKUJOU) && (play->csCtx.scriptIndex == 1)) {
        DmChar02_PlaySfxForDroppingOcarinaCutscene(this, play);
    }
}
