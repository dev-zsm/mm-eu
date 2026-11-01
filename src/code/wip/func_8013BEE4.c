#include "types.h"

typedef struct {
    u8 count;
    u8 additionalPathIndex;
    u8 pad2[6];
} Path;

typedef struct {
    u8 pad0[0x18864];
    Path *pathList;
} PlayState;

Path *SubS_GetAdditionalPath(PlayState *play, u8 pathIndex, s32 limit) {
    Path *path;
    s32 i = 0;

    do {
        path = &play->pathList[pathIndex];
        pathIndex = path->additionalPathIndex;
        i++;
    } while (i < limit && pathIndex != 0xFF);
    return path;
}
