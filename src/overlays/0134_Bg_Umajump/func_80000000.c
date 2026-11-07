// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_umajump.h"

void ref_func_80919F30(BgUmajump* this, PlayState* play) {
    if (this->rotationTimer >= 90) {
        this->rotationTimer = 0;
    }

    this->rotationTimer++;
    this->dyna.actor.shape.yOffset =
        Math_SinS((this->rotationTimer / 90.0f) * 0x10000) * (20.0f / this->dyna.actor.scale.y);
}
