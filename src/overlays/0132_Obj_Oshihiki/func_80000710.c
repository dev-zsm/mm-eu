// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

s16 ObjOshihiki_GetHighestFloor(ObjOshihiki* this) {
    s32 i;
    s16 highestFloor = 0;

    for (i = 1; i < ARRAY_COUNT(this->floorHeights); i++) {
        if (this->floorHeights[i] > this->floorHeights[highestFloor]) {
            highestFloor = i;
        } else if ((this->floorBgIds[i] == BGCHECK_SCENE) &&
                   ((this->floorHeights[i] - this->floorHeights[highestFloor]) > -0.001f)) {
            highestFloor = i;
        }
    }

    return highestFloor;
}
