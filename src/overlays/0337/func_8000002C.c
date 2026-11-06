// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_fireshield.h"

void ref_func_80A4CABC(ObjFireshield* this) {
    s32 pad;

    if (CutsceneManager_IsNext(this->actor.csId)) {
        s32 sp18 = OBJFIRESHIELD_GET_FLAGS(&this->actor);
        s32 temp_a0 = (sp18 & ~0x1F) >> 5;

        CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        this->actionFunc = ref_func_80A4CB7C;
        this->unk_194 = 20;
        ref_D_80A4D884[temp_a0] |= 1 << (sp18 & 0x1F);
        ref_D_80A4D894[temp_a0] |= 1 << (sp18 & 0x1F);
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}
