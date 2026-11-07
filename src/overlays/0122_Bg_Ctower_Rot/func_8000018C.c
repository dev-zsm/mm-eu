// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ctower_rot.h"

void BgCtowerRot_CorridorRotate(BgCtowerRot* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f offset;
    f32 rotZ;

    Actor_WorldToActorCoords(&this->dyna.actor, &offset, &player->actor.world.pos);
    rotZ = CLAMP(1100.0f - offset.z, 0.0f, 1000.0f);
    Camera_ChangeSetting(play->cameraPtrs[CAM_ID_MAIN], CAM_SET_DUNGEON0);
    this->dyna.actor.shape.rot.z = rotZ * 16.384f;

    if (play->csCtx.curFrame == 132) {
        Audio_PlaySfx(NA_SE_SY_SPIRAL_DASH);
    }
}
