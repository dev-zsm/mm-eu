// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lupygamelift.h"

void ObjLupygamelift_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    ObjLupygamelift* this = (ObjLupygamelift*)thisx;
    Path* path;
    s32 params;

    Actor_ProcessInitChain(thisx, sInitChain);
    this->dyna.actor.scale.y = 0.15f;
    this->dyna.actor.shape.rot.x = 0;
    this->dyna.actor.world.rot.x = 0;
    this->dyna.actor.shape.rot.z = 0;
    this->dyna.actor.world.rot.z = 0;
    this->timer = 0;
    Actor_UpdateBgCheckInfo(play, thisx, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);
    ActorShape_Init(&thisx->shape, 0.0f, ActorShadow_DrawSquare, 0.0f);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_raillift_Colheader_0048D0);
    this->targetSpeedXZ = thisx->home.rot.z * 0.1f;
    if (this->targetSpeedXZ < 0.0f) {
        this->targetSpeedXZ = -this->targetSpeedXZ;
    }
    this->dyna.actor.home.rot.x = 0;
    this->dyna.actor.home.rot.y = 0;
    this->dyna.actor.home.rot.z = 0;

    path = &play->setupPathList[OBJLUPYGAMELIFT_GET_PATH_INDEX(thisx)];
    this->pointIndex = OBJLUPYGAMELIFT_GET_START_POINT(thisx);
    this->pointCount = path->count;
    if (this->pointIndex >= this->pointCount) {
        this->pointIndex = 0;
    }
    this->pathPoints = Lib_SegmentedToVirtual(path->points);
    Actor_SpawnAsChild(&play->actorCtx, &this->dyna.actor, play, ACTOR_OBJ_ETCETERA, this->dyna.actor.world.pos.x,
                       this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z, this->dyna.actor.shape.rot.x,
                       this->dyna.actor.shape.rot.y, this->dyna.actor.shape.rot.z, 0);
    if (OBJLUPYGAMELIFT_GET_RUPEE_COLOR(thisx) != ENGAMELUPY_TYPE_GREEN) {
        params = ENGAMELUPY_TYPE_BLUE;
    } else {
        params = ENGAMELUPY_TYPE_GREEN;
    }
    Actor_Spawn(&play->actorCtx, play, ACTOR_EN_GAMELUPY, this->dyna.actor.home.pos.x, this->dyna.actor.home.pos.y,
                this->dyna.actor.home.pos.z, 0, 0, 0, params);
    ObjLupygamelift_SetupWait(this);
}
