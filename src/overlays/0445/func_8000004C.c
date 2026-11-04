// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_danpei_movebg.h"

void BgDanpeiMovebg_Init(Actor* thisx, PlayState* play) {
    BgDanpeiMovebg* this = (BgDanpeiMovebg*)thisx;

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);

    this->objectSlot = SubS_GetObjectSlot(ref_D_80AF7530[BGDANPEIMOVEBG_GET_TYPE(thisx)], play);
    if (this->objectSlot <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->dyna.actor);
    }

    this->actionFunc = ref_func_80AF6EA8;
}
