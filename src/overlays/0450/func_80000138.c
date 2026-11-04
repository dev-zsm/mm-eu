// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_elf_msg5.h"

void ElfMsg5_Init(Actor* thisx, PlayState* play) {
    ElfMsg5* this = (ElfMsg5*)thisx;

    if (!ref_func_80AFD990(this, play)) {
        Actor_ProcessInitChain(&this->actor, sInitChainsInitChain);
        this->actor.shape.rot.z = 0;
        this->actionFunc = ref_func_80AFDB38;
        this->actor.home.rot.x = -0x961;
        this->actor.shape.rot.x = this->actor.shape.rot.y = this->actor.shape.rot.z;
    }
}
