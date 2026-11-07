// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hsblock.h"

void ObjHsblock_Init(Actor* thisx, PlayState* play) {
    ObjHsblock* this = (ObjHsblock*)thisx;

    DynaPolyActor_Init(&this->dyna, 0);
    DynaPolyActor_LoadMesh(play, &this->dyna, sColHeaders[OBJHSBLOCK_GET_3(thisx)]);
    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    ref_func_8093DEAC(this, play);

    switch (OBJHSBLOCK_GET_3(&this->dyna.actor)) {
        case 0:
        case 2:
            ref_func_8093E03C(this);
            break;

        case 1:
            if (Flags_GetSwitch(play, OBJHSBLOCK_GET_SWITCH_FLAG(thisx))) {
                ref_func_8093E03C(this);
            } else {
                ref_func_8093E05C(this);
            }
            break;

        default:
            break;
    }
}
