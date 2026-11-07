// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bigicicle.h"

void ref_func_80AE8FD4(ObjBigicicle* this, PlayState* play) {
    if ((this->collider1.base.acFlags & AC_HIT) ||
        ((this->collider2.base.acFlags & AC_HIT) && (this->collider2.elem.acHitElem->atDmgInfo.dmgFlags & 0x3820))) {
        if ((this->unk_148 == 0) || (this->unk_149 == 1)) {
            CutsceneManager_Queue(this->actor.csId);
            this->actionFunc = ref_func_80AE9090;
            return;
        }

        ref_func_80AE8DE4(this, play);
        this->unk_149++;
        this->unk_14A = 50;
        this->actionFunc = ref_func_80AE9180;
    }
}
