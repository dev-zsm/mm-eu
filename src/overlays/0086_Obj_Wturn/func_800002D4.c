// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_wturn.h"

void ObjWturn_SetupFallingCs(ObjWturn* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    this->actor.world.pos.y += this->actor.playerHeightRel;
    player->actor.shape.shadowAlpha = 0;
    Player_SetCsActionWithHaltedActors(play, &this->actor, PLAYER_CSACTION_84);
    Player_PlaySfx(player, NA_SE_VO_NAVY_ENEMY);
    this->fallingFrame = 0;
    Play_DisableMotionBlur();
    this->actionFunc = ObjWturn_FallingCs;
}
