// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_eff_kamejima_wave.h"

void EffKamejimaWave_Init(Actor* thisx, PlayState* play) {
    EffKamejimaWave* this = (EffKamejimaWave*)thisx;

    Actor_SetScale(&this->actor, 0.2f);
    this->actor.scale.y = 0.0f;
    if (EFFKAMEJIMAWAVE_GET_F(thisx) == EFFKAMEJIMAWAVE_PARAM_1) {
        this->actionFunc = ref_func_80BCEDE0;
        sVtxAlpha = 255;
    } else {
        this->actionFunc = ref_func_80BCEC6C;
        sVtxAlpha = 255;
    }
    ref_D_80BCF1C4 = Lib_SegmentedToVirtual(gTurtleWaveTexAnim);
}
