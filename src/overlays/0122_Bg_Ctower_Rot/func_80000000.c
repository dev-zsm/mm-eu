// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ctower_rot.h"

void BgCtowerRot_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    BgCtowerRot* this = (BgCtowerRot*)thisx;
    Player* player;
    Vec3f offset;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    if (this->dyna.actor.params == BGCTOWERROT_CORRIDOR) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gClockTowerCorridorCol);
        this->actionFunc = BgCtowerRot_CorridorRotate;
        return;
    }

    player = GET_PLAYER(play);
    if (this->dyna.actor.params == BGCTOWERROT_STONE_DOOR_MAIN) {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gClockTowerStoneDoorMainCol);
        this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y + 0x4000;
    } else {
        DynaPolyActor_LoadMesh(play, &this->dyna, &gClockTowerStoneDoorCol);
        this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y - 0x4000;
    }
    Actor_WorldToActorCoords(&this->dyna.actor, &offset, &player->actor.world.pos);
    if (offset.z < 0.0f) {
        this->dyna.actor.world.pos.x = this->dyna.actor.home.pos.x + (Math_SinS(this->dyna.actor.world.rot.y) * 80.0f);
        this->dyna.actor.world.pos.z = this->dyna.actor.home.pos.z + (Math_CosS(this->dyna.actor.world.rot.y) * 80.0f);
        this->timer = 80.0f;
        this->actionFunc = BgCtowerRot_DoorIdle;
    } else {
        this->actionFunc = BgCtowerRot_DoorDoNothing;
    }
}
