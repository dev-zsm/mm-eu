// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_Destroy(Actor* thisx, PlayState* play) {
    BgNumaHana* this = (BgNumaHana*)thisx;

    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
    if (BG_NUMA_HANA_GET_TYPE(&this->dyna.actor) == BG_NUMA_HANA_TYPE_NORMAL) {
        FireObj_Destroy(play, &this->fire);
        Collider_DestroyCylinder(play, &this->torchCollider);
    }
}
