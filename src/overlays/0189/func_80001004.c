// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kakasi.h"

void func_80001004(EnKakasi* this, PlayState* play) {
    this->picto.actor.textId = 0x1646;
    Message_StartTextbox(play, this->picto.actor.textId, &this->picto.actor);
    this->subCamId = SUB_CAM_ID_DONE;
    this->subCamFov = 0.0f;
    this->subCamFovNext = 60.0f;
    EnKakasi_ChangeAnim(this, ENKAKASI_ANIM_TWIRL);
    this->unkState196 = 2;
    this->actionFunc = EnKakasi_OcarinaRemark;
}
