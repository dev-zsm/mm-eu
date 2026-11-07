// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void BgIkanaRotaryroom_Update(Actor* thisx, PlayState* play) {
    BgIkanaRotaryroom* this = (BgIkanaRotaryroom*)thisx;
    BgIkanaRotaryroomStruct1* ptr;
    BgIkanaRotaryroomStruct1* ptr2;
    BgIkanaRotaryroomStruct2* ptr3;
    s32 i;

    if ((this->unk_204.unk_00 != NULL) && (this->unk_204.unk_00->update == NULL)) {
        this->unk_204.unk_00 = NULL;
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_248); i++) {
        ptr = &this->unk_248[i];
        if ((ptr->unk_00 != NULL) && (ptr->unk_00->update == NULL)) {
            ptr->unk_00 = NULL;
        }
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_2D0); i++) {
        ptr2 = &this->unk_2D0[i];
        if ((ptr2->unk_00 != NULL) && (ptr2->unk_00->update == NULL)) {
            ptr2->unk_00 = NULL;
        }
    }

    for (i = 0; i < ARRAY_COUNT(this->unk_3E0); i++) {
        ptr3 = &this->unk_3E0[i];
        if ((ptr3->unk_00 != NULL) && (ptr3->unk_00->update == NULL)) {
            ptr3->unk_00 = NULL;
        }
    }

    if (ref_func_80B80F08(this, play)) {
        if (this->unk_204.unk_00 != NULL) {
            ((BgIkanaBlock*)this->unk_204.unk_00)->unk_17E = 1;
        }
    }

    this->unk_200(&this->dyna.actor, play);

    if (this->unk_578 != NULL) {
        this->unk_578(this, play);
    }

    if (this->unk_57C != NULL) {
        this->unk_57C(this, play);
    }

    if (this->actionFunc != NULL) {
        this->actionFunc(this, play);
    }
}
