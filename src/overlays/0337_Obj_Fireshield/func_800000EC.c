// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ref_func_80A4CB7C(ObjFireshield* this) {
    s32 pad;
    s32 sp18 = OBJFIRESHIELD_GET_FLAGS(&this->actor);

    if (this->unk_194 > 0) {
        if (this->unk_194 == 20) {
            ref_D_80A4D884[(sp18 & ~0x1F) >> 5] &= ~(1 << (sp18 & 0x1F));
        }
        this->unk_194--;
        return;
    }

    CutsceneManager_Stop(this->actor.csId);
    this->actionFunc = ref_func_80A4CD28;
    ref_D_80A4D894[(sp18 & ~0x1F) >> 5] &= ~(1 << (sp18 & 0x1F));
}
