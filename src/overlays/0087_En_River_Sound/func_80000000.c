// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_river_sound.h"

void EnRiverSound_Init(Actor* thisx, PlayState* play) {
    s32 pad;
    EnRiverSound* this = (EnRiverSound*)thisx;
    Path* path;
    s32 pathIndex;

    this->playSound = false;
    pathIndex = RS_GET_PATH_INDEX(&this->actor);
    this->actor.params = RS_GET_TYPE(&this->actor);
    if (pathIndex == RS_PATH_INDEX_NONE) {
        Actor_Kill(&this->actor);
        return;
    }

    path = &play->setupPathList[pathIndex];
    this->pathPoints = Lib_SegmentedToVirtual(path->points);
    this->numPoints = path->count;
}
