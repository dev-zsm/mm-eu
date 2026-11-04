// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/c_keyframe.h"

s32 Keyframe_UpdateFlex(KFSkelAnimeFlex* kfSkelAnime) {
    s32 limbIndex;
    s32 pad[2];
    u16* bitFlags;
    s16* outputValues;
    s32 kfn = 0;
    s32 fixedValueIndex = 0;
    s32 kfStart = 0;
    s16* fixedValues;
    KeyFrame* keyFrames;
    s16* kfNums;
    u32 bit;
    s32 i;
    s32 j;

    
    if (kfSkelAnime->morphFrames != 0.0f) {
        outputValues = (s16*)kfSkelAnime->morphTable;
    } else {
        outputValues = (s16*)kfSkelAnime->jointTable;
    }

    
    fixedValues = Lib_SegmentedToVirtual(kfSkelAnime->animation->fixedValues);

    
    kfNums = Lib_SegmentedToVirtual(kfSkelAnime->animation->kfNums);

    
    keyFrames = Lib_SegmentedToVirtual(kfSkelAnime->animation->keyFrames);

    
    
    
    
    
    
    
    
    
    
    
    
    
    bitFlags = Lib_SegmentedToVirtual(kfSkelAnime->animation->bitFlags.flex);

    
    for (limbIndex = 0; limbIndex < kfSkelAnime->skeleton->limbCount; limbIndex++) {
        bit = 1 << (3 * 3 - 1);

        
        for (i = 0; i < 3; i++) {
            
            for (j = 0; j < 3; j++) {
                if (bitFlags[limbIndex] & bit) {
                    
                    *outputValues = Keyframe_KeyCalc(kfStart, kfNums[kfn], keyFrames, kfSkelAnime->frameCtrl.curTime);
                    kfStart += kfNums[kfn];
                    kfn++;
                } else {
                    
                    *outputValues = fixedValues[fixedValueIndex];
                    fixedValueIndex++;
                }
                bit >>= 1;

                if (i == 1) {
                    
                    *outputValues = DEG_TO_BINANG(FMOD(*outputValues * 0.1f, 360));
                }
                outputValues++;
            }
        }
    }

    if (IS_ZERO(kfSkelAnime->morphFrames)) {
        
        return FrameCtrl_Update(&kfSkelAnime->frameCtrl);
    } else if (kfSkelAnime->morphFrames > 0.0f) {
        
        Keyframe_FlexMorphInterpolation(kfSkelAnime);
        kfSkelAnime->morphFrames -= 1.0f;
        if (kfSkelAnime->morphFrames <= 0.0f) {
            kfSkelAnime->morphFrames = 0.0f;
        }
        return KEYFRAME_NOT_DONE;
    } else {
        
        Keyframe_FlexMorphInterpolation(kfSkelAnime);
        kfSkelAnime->morphFrames += 1.0f;
        if (kfSkelAnime->morphFrames >= 0.0f) {
            kfSkelAnime->morphFrames = 0.0f;
        }
        return FrameCtrl_Update(&kfSkelAnime->frameCtrl);
    }
}
