// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_skelanime.h"

void SkelAnime_GetFrameData(AnimationHeader* animation, s32 frame, s32 limbCount, Vec3s* frameTable) {
    AnimationHeader* animHeader = Lib_SegmentedToVirtual(animation);
    JointIndex* jointIndices = Lib_SegmentedToVirtual(animHeader->jointIndices);
    s16* frameData = Lib_SegmentedToVirtual(animHeader->frameData);
    s16* dynamicData = &frameData[frame];
    s32 i;
    u16 staticIndexMax = animHeader->staticIndexMax;

    for (i = 0; i < limbCount; i++) {
        
        if ((frameTable == NULL) || (jointIndices == NULL) || (dynamicData == NULL)) {}
        frameTable->x = jointIndices->x >= staticIndexMax ? dynamicData[jointIndices->x] : frameData[jointIndices->x];
        frameTable->y = jointIndices->y >= staticIndexMax ? dynamicData[jointIndices->y] : frameData[jointIndices->y];
        frameTable->z = jointIndices->z >= staticIndexMax ? dynamicData[jointIndices->z] : frameData[jointIndices->z];
        jointIndices++;
        frameTable++;
    }
}
