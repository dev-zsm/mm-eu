// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void DoorWarp1_Draw(Actor* thisx, PlayState* play) {
    DoorWarp1* this = (DoorWarp1*)thisx;

    switch (DOORWARP1_GET_FF(&this->dyna.actor)) {
        case ENDOORWARP1_FF_0:
            ref_func_808BAE9C(this, play);
            break;

        case ENDOORWARP1_FF_1:
            ref_func_808BACCC(this, play);
            ref_func_808BAE9C(this, play);
            break;

        case ENDOORWARP1_FF_2:
        case ENDOORWARP1_FF_3:
        case ENDOORWARP1_FF_4:
        case ENDOORWARP1_FF_5:
            ref_func_808BB4C4(this, play);
            break;

        case ENDOORWARP1_FF_6:
            ref_func_808BB4F4(this, play);
            break;
    }
}
