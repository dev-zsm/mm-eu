// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ingate.h"

s32 ref_func_80953DA8(BgIngate* this, PlayState* play) {
    Camera* mainCam = Play_GetCamera(play, CAM_ID_MAIN);

    if (CHECK_EVENTINF(EVENTINF_35)) {
        Player_SetCsActionWithHaltedActors(play, &this->dyna.actor, PLAYER_CSACTION_WAIT);
    } else {
        SET_EVENTINF(EVENTINF_41);
    }
    Camera_ChangeSetting(mainCam, CAM_SET_BOAT_CRUISE);
    play->bButtonAmmoPlusOne = 99;

    return false;
}
