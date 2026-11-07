// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test.h"

void EnTest_Update(Actor* thisx, PlayState* play) {
    EnTest* this = (EnTest*)thisx;
    s32 i;

    this->unk_208 = this->kfSkelAnime.frameCtrl.curTime;

    if (Keyframe_UpdateFlex(&this->kfSkelAnime) && (this->actor.parent == NULL) && (this->actor.params != -1)) {
        this->unk_209++;
        if (this->unk_209 > 20) {
            Actor_Kill(&this->actor);
        }
    }

    if ((this->actor.params != -1) && (this->unk_208 >= 2)) {
        if (!(this->unk_174 & 1)) {
            this->unk_174 |= 1;

            for (i = 0; i < ARRAY_COUNT(this->unk_20C); i++) {
                ref_func_80862CBC(this->unk_20C, &this->actor.world.pos);
            }
        }
    }
    ref_func_80862EDC(this->unk_20C);
}
