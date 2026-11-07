// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_paper.h"

void EnPaper_UpdateWind(EnPaper* this) {
    f32 strength = (Rand_Centered() * 4.0f) + 6.0f;
    f32 cosX;

    this->windForce.y = Math_SinS(this->actor.shape.rot.x) * -strength;
    cosX = Math_CosS(this->actor.shape.rot.x) * -strength;
    this->windForce.x = Math_SinS(this->actor.shape.rot.y) * cosX;
    this->windForce.z = Math_CosS(this->actor.shape.rot.y) * cosX;

    
    
    this->actor.shape.rot.x += (s16)(Rand_Next() >> 8);
    this->actor.shape.rot.y += (s16)(Rand_Next() >> 6);

    
    if (ABS_ALT(this->actor.shape.rot.x) > WIND_PITCH_BOUND) {
        if (this->actor.shape.rot.x > 0) {
            this->actor.shape.rot.x = WIND_PITCH_BOUND;
        } else {
            this->actor.shape.rot.x = -WIND_PITCH_BOUND;
        }
    }
}
