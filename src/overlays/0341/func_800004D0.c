// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_dnb.h"

void EnDnb_Init(Actor* thisx, PlayState* play) {
    EnDnb* this = (EnDnb*)thisx;
    s32 i;
    s16* alloc;

    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &object_hanareyama_obj_Colheader_004D8C);

    alloc = Lib_SegmentedToVirtual(object_hanareyama_obj_Vec_004710);
    for (i = 0; i < ARRAY_COUNT(this->effects); i++) {
        ref_func_80A4FDD0(&this->effects[i], this, alloc, i);
    }

    Actor_SetScale(&this->dyna.actor, 1.0f);
}
