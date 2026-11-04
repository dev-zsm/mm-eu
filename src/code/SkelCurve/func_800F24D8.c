// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_fcurve_data_skelanime.h"

s32 SkelCurve_Update(PlayState* play, SkelCurve* skelCurve) {
    s16* jointData;
    u8* knotCounts;
    CurveAnimationHeader* animation;
    u16* constantData;
    s32 curLimb;
    s32 ret = false;
    s32 coord;
    CurveInterpKnot* startKnot;
    s32 vecType;

    animation = Lib_SegmentedToVirtual(skelCurve->animation);
    knotCounts = Lib_SegmentedToVirtual(animation->knotCounts);
    startKnot = Lib_SegmentedToVirtual(animation->interpolationData);
    constantData = Lib_SegmentedToVirtual(animation->constantData);
    jointData = *skelCurve->jointTable;

    skelCurve->curFrame += skelCurve->playSpeed * ((s32)play->state.framerateDivisor * 0.5f);

    if (((skelCurve->playSpeed >= 0.0f) && (skelCurve->curFrame > skelCurve->endFrame)) ||
        ((skelCurve->playSpeed < 0.0f) && (skelCurve->curFrame < skelCurve->endFrame))) {
        skelCurve->curFrame = skelCurve->endFrame;
        ret = true;
    }

    for (curLimb = 0; curLimb < skelCurve->limbCount; curLimb++) {

        
        for (vecType = SKELCURVE_VEC_TYPE_SCALE; vecType < SKELCURVE_VEC_TYPE_MAX; vecType++) {

            
            for (coord = 0; coord < 3; coord++) {
                f32 transformValue;

                if (*knotCounts == 0) {
                    transformValue = *constantData;
                    *jointData = transformValue;
                    constantData++;
                } else {
                    transformValue = Curve_Interpolate(skelCurve->curFrame, startKnot, *knotCounts);
                    startKnot += *knotCounts;
                    if (vecType == SKELCURVE_VEC_TYPE_SCALE) {
                        
                        *jointData = transformValue * SKELCURVE_SCALE_SCALE;
                    } else if (vecType == SKELCURVE_VEC_TYPE_ROTATION) {
                        
                        *jointData = DEG_TO_BINANG(transformValue);
                    } else { 
                        
                        *jointData = transformValue * SKELCURVE_SCALE_POSITION;
                    }
                }
                knotCounts++;
                jointData++;
            }
        }
    }

    return ret;
}
