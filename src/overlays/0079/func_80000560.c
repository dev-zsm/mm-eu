// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_viewer.h"

void EnViewer_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnViewer* this = (EnViewer*)thisx;

    if (ref_D_8089F4D0 != play->state.frames) {
        ref_D_8089F4D0 = play->state.frames;
        ref_D_8089F3E4 = 0;
    }

    this->actionFunc(this, play);
}
