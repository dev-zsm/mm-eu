// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_Update(Actor* thisx, PlayState* play) {
    EnTest7* this = (EnTest7*)thisx;

    this->actionFunc(this, play);

    if (this->playerCamFunc != NULL) {
        this->playerCamFunc(this, play);
    }

    this->timer++;

    EnTest7_UpdateFeathers(play, this->feathers, this, (this->flags & OWL_WARP_FLAGS_8) != 0,
                           (this->flags & OWL_WARP_FLAGS_10) != 0);
}
