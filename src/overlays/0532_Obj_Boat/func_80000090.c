// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_boat.h"

void ObjBoat_Init(Actor* thisx, PlayState* play) {
    s32 pad[2];
    Path* path;
    ObjBoat* this = (ObjBoat*)thisx;
    Vec3f sp24;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS | DYNA_TRANSFORM_ROT_Y);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_kaizoku_obj_Colheader_009A88);
    if (thisx->params < 0) {
        this->dyna.actor.update = ObjBoat_UpdateCutscene;
    } else {
        path = &play->setupPathList[OBJBOAT_GET_PATH_INDEX(thisx)];
        this->maxPointIndex = path->count - 1;
        this->pathPoints = Lib_SegmentedToVirtual(path->points);
        this->direction = 1;
        this->dyna.actor.world.pos.x = this->pathPoints[this->curPointIndex].x;
        this->dyna.actor.world.pos.z = this->pathPoints[this->curPointIndex].z;
        this->dyna.actor.shape.rot.y = ObjBoat_GetNextPoint(this, &sp24);
        this->dyna.actor.world.rot.y = this->dyna.actor.shape.rot.y;
        this->direction = -this->direction;
    }
}
