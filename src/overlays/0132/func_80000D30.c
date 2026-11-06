// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

void ObjOshihiki_OnScene(ObjOshihiki* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);

    this->stateFlags |= PUSHBLOCK_ON_SCENE;

    if (this->timer <= 0) {
        if (fabsf(this->dyna.pushForce) > 0.001f) {
            if (ObjOshihiki_StrongEnough(this, play)) {
                if (!ObjOshihiki_CheckWall(play, this->dyna.yRotation, this->dyna.pushForce, this)) {
                    this->direction = this->dyna.pushForce;
                    ObjOshihiki_SetupPush(this, play);
                    return;
                }
            }
            player->stateFlags2 &= ~PLAYER_STATE2_10;
            this->dyna.pushForce = 0.0f;
        }
    } else if (fabsf(this->dyna.pushForce) > 0.001f) {
        player->stateFlags2 &= ~PLAYER_STATE2_10;
        this->dyna.pushForce = 0.0f;
    }
}
