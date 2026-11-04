// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_elf_msg5.h"

void ElfMsg5_Update(Actor* thisx, PlayState* play) {
    ElfMsg5* this = (ElfMsg5*)thisx;

    if ((this->actor.home.rot.y >= 0) || (this->actor.home.rot.y < -0x80) ||
        Flags_GetSwitch(play, -this->actor.home.rot.y - 1)) {
        this->actionFunc(this, play);
    }
}
