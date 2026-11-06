// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_makeoshihiki.h"

void ObjMakeoshihiki_Init(Actor* thisx, PlayState* play) {
    ObjMakeoshihiki* this = (ObjMakeoshihiki*)thisx;
    Vec3s* childPoint;
    Path* path;
    s32 childPointIndex;

    path = &play->setupPathList[OBJMAKEOSHIHIKI_GET_PATH_INDEX(&this->actor)];
    this->pathPoints = Lib_SegmentedToVirtual(path->points);
    this->pathCount = path->count;
    childPointIndex = ObjMakeoshihiki_GetChildSpawnPointIndex(this, play);
    childPoint = &this->pathPoints[childPointIndex];
    if (Actor_SpawnAsChild(&play->actorCtx, &this->actor, play, ACTOR_OBJ_OSHIHIKI, childPoint->x, childPoint->y,
                           childPoint->z, 0, 0, 0, 0xFFF1) == NULL) {
        Actor_Kill(&this->actor);
    }
}
