// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ObjHunsui_Update(Actor* thisx, PlayState* play) {
    ObjHunsui* this = (ObjHunsui*)thisx;

    this->actionFunc(this, play);

    if ((this->unk_172 & 0x40) &&
        SubS_StartCutscene(&this->dyna.actor, this->csId, CS_ID_NONE, SUBS_CUTSCENE_WITH_PLAYER)) {
        this->unk_172 &= ~0x40;
    }

    if (this->unk_1AC > 1024.0f) {
        this->unk_1AC -= 1024.0f;
    }

    if (this->unk_1AC <= 0.0f) {
        this->unk_1AC += 1024.0f;
    }
}
