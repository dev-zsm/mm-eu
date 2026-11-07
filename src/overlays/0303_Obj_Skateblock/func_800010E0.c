// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_skateblock.h"

void ObjSkateblock_Init(Actor* thisx, PlayState* play) {
    ObjSkateblock* this = (ObjSkateblock*)thisx;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gameplay_dangeon_keep_Colheader_007498);
    if (ref_D_80A22A18 == NULL) {
        ref_D_80A22A18 = Lib_SegmentedToVirtual(gameplay_dangeon_keep_Matanimheader_01B370);
    }
    ref_func_80A22308(this);
    this->unk_1C0 = ref_D_80A22A14;
    ref_D_80A22A14++;
    ref_D_80A22A14 &= 0x1F;
}
