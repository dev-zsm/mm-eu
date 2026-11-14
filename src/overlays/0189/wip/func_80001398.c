// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (EnKakasi_PostSongLearnTwirl), score 2.00 (2 differ, size +2)
#include "generated/mm/z_en_kakasi.h"

void func_80001398(EnKakasi* this, PlayState* play) {
    f32 curFrame = this->skelAnime.curFrame;

    if ((this->postTeachTimer == 0) && (this->animIndex != ENKAKASI_ANIM_TWIRL)) {
        EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_TWIRL);
        this->skelAnime.playSpeed = 2.0f;
    }
    if ((this->postTeachTimer == 0) && (this->animIndex == ENKAKASI_ANIM_TWIRL) && (curFrame >= this->animEndFrame)) {
        EnKakasi_SetupPostSongLearnDialogue(this, play);
    }
}
