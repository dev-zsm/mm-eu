// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_fall2.h"

void ref_func_80C1B8F0(EnFall2* this) {
    switch (this->cueId) {
        case 1:
            if (this->alphaLevel < 1.0f) {
                this->alphaLevel += 1.0f / 30.0f;
            } else {
                this->alphaLevel = 1.0f;
            }
            break;

        case 2:
            if (this->alphaLevel > 0.0f) {
                this->alphaLevel -= 0.1f;
                if (this->alphaLevel < 0.0f) {
                    this->alphaLevel = 0.0f;
                }
            }
            if (this->actor.scale.x > 0.0f) {
                this->actor.scale.x -= 20.0f * 0.0001f;
                if (this->actor.scale.x < 0.0f) {
                    this->actor.scale.x = 0.0f;
                }
                this->actor.scale.z = this->actor.scale.x;
            }
            break;

        default:
            break;
    }
}
