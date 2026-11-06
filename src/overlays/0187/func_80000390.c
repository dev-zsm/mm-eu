// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_elf_msg2.h"

void ref_func_8096EFD0(ElfMsg2* this, PlayState* play) {
    if ((this->actor.home.rot.y < 0) && (this->actor.home.rot.y >= -0x80) &&
        Flags_GetSwitch(play, -this->actor.home.rot.y - 1)) {
        ElfMsg2_SetupAction(this, ref_func_8096EF98);
        this->actor.flags |= (ACTOR_FLAG_ATTENTION_ENABLED | ACTOR_FLAG_TALK_WITH_C_UP);
        this->actor.textId = ref_func_8096EE50(this);
    }
}
