// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

void Keyframe_StandardMorphInterpolation(KFSkelAnime* kfSkelAnime) {
    Vec3s* jointTable = kfSkelAnime->jointTable;
    Vec3s* morphTable = kfSkelAnime->morphTable;
    f32 t = 1.0f / fabsf(kfSkelAnime->morphFrames);
    s32 limbIndex;

    
    Keyframe_MorphInterpolateLinear((s16*)jointTable, (s16*)morphTable, t);
    jointTable++;
    morphTable++;

    for (limbIndex = 0; limbIndex < kfSkelAnime->skeleton->limbCount; limbIndex++) {
        Vec3s frameRot;
        Vec3s morphRot;

        frameRot.x = jointTable->x;
        frameRot.y = jointTable->y;
        frameRot.z = jointTable->z;

        morphRot.x = morphTable->x;
        morphRot.y = morphTable->y;
        morphRot.z = morphTable->z;

        
        if (frameRot.x != morphRot.x || frameRot.y != morphRot.y || frameRot.z != morphRot.z) {
            Vec3s frameRotInv;
            f32 norm1;
            f32 norm2;

            frameRotInv.x = 0x7FFF + frameRot.x;
            frameRotInv.y = 0x7FFF - frameRot.y;
            frameRotInv.z = 0x7FFF + frameRot.z;

            
            norm1 = fabsf((f32)morphRot.x - frameRot.x) + fabsf((f32)morphRot.y - frameRot.y) +
                    fabsf((f32)morphRot.z - frameRot.z);
            norm2 = fabsf((f32)morphRot.x - frameRotInv.x) + fabsf((f32)morphRot.y - frameRotInv.y) +
                    fabsf((f32)morphRot.z - frameRotInv.z);

            if (norm1 < norm2) {
                
                Keyframe_MorphInterpolateRotation(t, &jointTable->x, frameRot.x, morphRot.x);
                Keyframe_MorphInterpolateRotation(t, &jointTable->y, frameRot.y, morphRot.y);
                Keyframe_MorphInterpolateRotation(t, &jointTable->z, frameRot.z, morphRot.z);
            } else {
                
                Keyframe_MorphInterpolateRotation(t, &jointTable->x, frameRotInv.x, morphRot.x);
                Keyframe_MorphInterpolateRotation(t, &jointTable->y, frameRotInv.y, morphRot.y);
                Keyframe_MorphInterpolateRotation(t, &jointTable->z, frameRotInv.z, morphRot.z);
            }
        }
        morphTable++;
        jointTable++;
    }
}
