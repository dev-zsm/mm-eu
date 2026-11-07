// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_PlayerAndSubCamAction(EnTest7* this, PlayState* play) {
    f32 lerp;

    if ((this->timer >= 12) && (this->timer <= 30)) {
        lerp = (this->timer - 12) / (f32)(30 - 12);
        EnTest7_UpdateSubCamWarpCs2(this, play, lerp);
    } else if ((this->timer >= 79) && (this->timer <= 95)) {
        lerp = (this->timer - 79) / (f32)(95 - 79);
        EnTest7_UpdateSubCamWarpCs1(this, play, lerp);
    }

    if ((this->timer >= 42) && (this->timer <= 68)) {
        lerp = (this->timer - 42) / (f32)(68 - 42);
        EnTest7_SpinAndSquishPlayer(this, play, lerp);
    }
}
