// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

s32 Keyframe_UpdateStandard(KFSkelAnime* kfSkelAnime) {
    s32 limbIndex;
    u32 bit;
    u8* bitFlags;
    s32 i;
    s32 kfn = 0;
    s32 fixedValueIndex = 0;
    s32 kfStart = 0;
    s16* fixedValues;
    KeyFrame* keyFrames;
    s16* kfNums;
    s16* outputValues;

    
    if (kfSkelAnime->morphFrames != 0.0f) {
        outputValues = (s16*)kfSkelAnime->morphTable;
    } else {
        outputValues = (s16*)kfSkelAnime->jointTable;
    }

    fixedValues = Lib_SegmentedToVirtual(kfSkelAnime->animation->fixedValues);
    kfNums = Lib_SegmentedToVirtual(kfSkelAnime->animation->kfNums);
    keyFrames = Lib_SegmentedToVirtual(kfSkelAnime->animation->keyFrames);

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    bitFlags = Lib_SegmentedToVirtual(kfSkelAnime->animation->bitFlags.standard);

    

    bit = 1 << (3 * 2 - 1);

    
    for (i = 0; i < 3; i++) {
        if (bitFlags[0] & bit) {
            *outputValues = Keyframe_KeyCalc(kfStart, kfNums[kfn], keyFrames, kfSkelAnime->frameCtrl.curTime);
            kfStart += kfNums[kfn++];
        } else {
            *outputValues = fixedValues[fixedValueIndex++];
        }
        bit >>= 1;
        outputValues++;
    }

    

    for (limbIndex = 0; limbIndex < kfSkelAnime->skeleton->limbCount; limbIndex++) {
        bit = 1 << (3 - 1);

        
        for (i = 0; i < 3; i++) {
            s32 pad;

            if (bitFlags[limbIndex] & bit) {
                *outputValues = Keyframe_KeyCalc(kfStart, kfNums[kfn], keyFrames, kfSkelAnime->frameCtrl.curTime);
                kfStart += kfNums[kfn++];
            } else {
                *outputValues = fixedValues[fixedValueIndex++];
            }
            bit >>= 1;

            
            *outputValues = DEG_TO_BINANG(FMOD(*outputValues * 0.1f, 360));
            outputValues++;
        }
    }

    if (kfSkelAnime->rotOffsetsTable != NULL) {
        Vec3s* table;

        if (kfSkelAnime->morphFrames != 0.0f) {
            table = kfSkelAnime->morphTable;
        } else {
            table = kfSkelAnime->jointTable;
        }
        table++; 

        
        for (limbIndex = 0; limbIndex < kfSkelAnime->skeleton->limbCount; limbIndex++, table++) {
            table->x = table->x + kfSkelAnime->rotOffsetsTable[limbIndex].x;
            table->y = table->y + kfSkelAnime->rotOffsetsTable[limbIndex].y;
            table->z = table->z + kfSkelAnime->rotOffsetsTable[limbIndex].z;
        }
    }

    if (IS_ZERO(kfSkelAnime->morphFrames)) {
        
        return FrameCtrl_Update(&kfSkelAnime->frameCtrl);
    } else if (kfSkelAnime->morphFrames > 0.0f) {
        
        Keyframe_StandardMorphInterpolation(kfSkelAnime);
        kfSkelAnime->morphFrames -= 1.0f;
        if (kfSkelAnime->morphFrames <= 0.0f) {
            kfSkelAnime->morphFrames = 0.0f;
        }
        return KEYFRAME_NOT_DONE;
    } else {
        
        Keyframe_StandardMorphInterpolation(kfSkelAnime);
        kfSkelAnime->morphFrames += 1.0f;
        if (kfSkelAnime->morphFrames >= 0.0f) {
            kfSkelAnime->morphFrames = 0.0f;
        }
        return FrameCtrl_Update(&kfSkelAnime->frameCtrl);
    }
}
