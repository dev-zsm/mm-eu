// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_SetupDigAway), score 1.00 (1 differ, size +1)
#include "generated/mm/z_en_kakasi.h"

void func_80001E60(EnKakasi* this) {
    if (this->animIndex != ENKAKASI_ANIM_SIDEWAYS_SHAKING) {
        EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_SIDEWAYS_SHAKING);
    }
    this->unk190 = 0;
    this->unkCounter1A4 = 0;
    this->subCamFovNext = 60.0f;
    this->subCamFov = 60.0f;
    Math_Vec3f_Copy(&this->unk22C, &this->picto.actor.home.pos);
    this->unkState196 = 4;
    this->actionFunc = EnKakasi_DiggingAway;
}
