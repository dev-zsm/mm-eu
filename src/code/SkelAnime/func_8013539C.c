// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

s16 SkelAnime_GetFrameDataLegacy(LegacyAnimationHeader* animation, s32 frame, Vec3s* frameTable) {
    LegacyAnimationHeader* animHeader = Lib_SegmentedToVirtual(animation);
    s16 limbCount = animHeader->limbCount;
    LegacyJointKey* key = Lib_SegmentedToVirtual(animHeader->jointKey);
    s16* frameData = Lib_SegmentedToVirtual(animHeader->frameData);
    s16* staticData = &frameData[0];
    s16* dynamicData = &frameData[frame];
    s32 i;

    frameTable->x = frame < key->xMax ? dynamicData[key->x] : staticData[key->x];
    frameTable->y = frame < key->yMax ? dynamicData[key->y] : staticData[key->y];
    frameTable->z = frame < key->zMax ? dynamicData[key->z] : staticData[key->z];

    frameTable++;
    key++;

    for (i = 1; i <= limbCount; i++, key++, frameTable++) {
        frameTable->x = frame < key->xMax ? dynamicData[key->x] : staticData[key->x];
        frameTable->y = frame < key->yMax ? dynamicData[key->y] : staticData[key->y];
        frameTable->z = frame < key->zMax ? dynamicData[key->z] : staticData[key->z];
    }

    return limbCount;
}
