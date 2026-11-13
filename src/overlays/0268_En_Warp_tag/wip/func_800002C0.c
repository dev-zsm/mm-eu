// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnWarpTag_Unused809C0A20), score 5.00 (5 differ, size +3)
#include "generated/mm/z_en_warp_tag.h"

void func_800002C0(EnWarptag* this, PlayState* play) {
    if (play->msgCtx.ocarinaMode == OCARINA_MODE_PLAYED_STORMS) {
        Player_SetCsActionWithHaltedActors(play, NULL, PLAYER_CSACTION_WAIT);
        this->actionFunc = EnWarpTag_RespawnPlayer;
        CutsceneManager_Stop(CutsceneManager_GetCurrentCsId());

    } else if (play->msgCtx.ocarinaMode >= OCARINA_MODE_WARP) {
        play->msgCtx.ocarinaMode = OCARINA_MODE_END;
        this->actionFunc = EnWarpTag_Unused809C09A0;
    }
}
