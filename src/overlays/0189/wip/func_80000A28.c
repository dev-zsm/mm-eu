// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_SetupDialogue), score 3.00 (3 differ, size +3)
#include "generated/mm/z_en_kakasi.h"

void func_80000A28(EnKakasi* this) {
    
    if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
        EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
    }

    this->talkState = TEXT_STATE_EVENT;
    this->unkState196 = 1;
    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SPIN_REACH_OFFER);
    this->actionFunc = EnKakasi_RegularDialogue;
}
