// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_danpeilift.h"

void func_8000003C(Actor* thisx, PlayState* play) {
    Path* path;
    ObjDanpeiliftActionFunc tempActionFunc;
    ObjDanpeilift* this = (ObjDanpeilift*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->dyna.actor.world.rot.z = 0;
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_obj_danpeilift_Colheader_000BA0);
    if (this->dyna.bgId == BG_ACTOR_MAX) {
        Actor_Kill(&this->dyna.actor);
        return;
    }

    this->speed = OBJDANPEILIFT_GET_SPEED(thisx);
    if (this->speed < 0.0f) {
        this->speed = -this->speed;
    }
    if (this->speed < 0.01f) {
        this->actionFunc = ObjDanpeilift_DoNothing;
    } else {
        path = &play->setupPathList[OBJDANPEILIFT_GET_PATH_INDEX(thisx)];
        this->curPoint = OBJDANPEILIFT_GET_STARTING_POINT(thisx);
        this->endPoint = path->count - 1;
        this->direction = 1;
        this->pathPoints = Lib_SegmentedToVirtual(path->points);
        ObjDanpeilift_UpdatePosition(this, this->curPoint);
        this->actionFunc = ObjDanpeilift_Move;
    }
}
