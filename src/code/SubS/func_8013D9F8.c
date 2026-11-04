#include "types.h"

typedef struct {
    u8 count;
    u8 unk1;
    u8 pad2[6];
} Path;

typedef struct {
    u8 pad0[0x18864];
    Path *pathList;
} PlayState;

Path *SubS_GetPathByIndex(PlayState *play, s16 index, s16 notSetIndex) {
    return (index != notSetIndex) ? &play->pathList[index] : NULL;
}
