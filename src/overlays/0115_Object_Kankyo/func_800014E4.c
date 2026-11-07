// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ObjectKankyo_Draw(Actor* thisx, PlayState* play) {
    ObjectKankyo* this = (ObjectKankyo*)thisx;

    switch (this->actor.params) {
        case 0:
            ref_func_808DDE9C(thisx, play);
            break;

        case 1:
        case 2:
        case 3:
            ref_func_808DD3C8(thisx, play);
            break;

        case 4:
            ref_func_808DD970(thisx, play);
            break;
    }
}
