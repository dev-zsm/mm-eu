// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_SetupArriveCs(EnTest7* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    this->playerDrawFunc = player->actor.draw;
    player->actor.draw = NULL;
    player->stateFlags2 |= PLAYER_STATE2_20000000;
    this->flags |= OWL_WARP_FLAGS_DRAW_WIND_CAPSULE;
    this->windCapsule.unk_04 = 30.0f;

    if (play->roomCtx.curRoom.type != ROOM_TYPE_DUNGEON) {
        EnTest7_SetupAction(this, EnTest7_StartArriveCs);
    } else {
        EnTest7_SetupAction(this, EnTest7_StartArriveCsSkip);
    }
}
