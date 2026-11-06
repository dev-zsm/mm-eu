// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void ref_func_80B23934(EnHanabi* this, PlayState* play) {
    if ((gSaveContext.save.entrance == ENTRANCE(TERMINA_FIELD, 1)) && (gSaveContext.sceneLayer == 7)) {
        if (play->csCtx.curFrame > 1650) {
            ref_func_80B236C8(this, play);
            Actor_PlaySfx_FlaggedCentered2(&this->actor, NA_SE_EV_FIREWORKS_LAUNCH - SFX_FLAG);
        }
    }

    if ((play->sceneId == SCENE_00KEIKOKU) && (gSaveContext.sceneLayer == 7) && (play->csCtx.scriptIndex == 0) &&
        (play->csCtx.curFrame == 610)) {
        Actor_PlaySfx(&this->actor, NA_SE_EV_KYOJIN_GROAN);
    }
}
