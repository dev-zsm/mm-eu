// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_twig.h"

void EnTwig_Draw(Actor* thisx, PlayState* play) {
    EnTwig* this = (EnTwig*)thisx;

    switch (this->unk_160) {
        case 1:
            Gfx_DrawDListOpa(play, object_twig_DL_001C38);
            break;

        case 2:
            Gfx_DrawDListOpa(play, object_twig_DL_0014C8);
            break;
    }
}
