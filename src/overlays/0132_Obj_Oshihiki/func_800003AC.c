// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_oshihiki.h"

void ObjOshihiki_SetTextureStep(ObjOshihiki* this, PlayState* play) {
    switch (OBJOSHIHIKI_GET_F(&this->dyna.actor)) {
        case OBJOSHIHIKI_F_0:
        case OBJOSHIHIKI_F_3:
            this->textureStep = 0;
            break;

        case OBJOSHIHIKI_F_1:
        case OBJOSHIHIKI_F_4:
            this->textureStep = 1;
            break;

        case OBJOSHIHIKI_F_2:
        case OBJOSHIHIKI_F_5:
            this->textureStep = 2;
            break;
    }
}
