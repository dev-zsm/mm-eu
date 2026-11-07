// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hakaisi.h"

void ref_func_80B14648(ObjHakaisi* this, PlayState* play) {
    if (this->unk_19A < 2) {
        ref_func_80B14CF8(play, this->unk_160[this->unk_194], 100, 30, 5);
    }

    this->unk_19A++;

    if (this->dyna.actor.colChkInfo.health == 0) {
        ref_func_80B14A24(this, play, this->unk_160[this->unk_194]);
        ref_func_80B14A24(this, play, this->unk_160[this->unk_194]);
        ref_func_80B14B6C(this, play, this->unk_160[this->unk_194], 70);
        Flags_SetSwitch(play, this->switchFlag);
        this->dyna.actor.draw = NULL;
        ref_func_80B149A8(this);
    }

    if (this->unk_19E != this->dyna.actor.colChkInfo.health) {
        if ((this->unk_19E > 20) && (this->dyna.actor.colChkInfo.health <= 20)) {
            ref_func_80B14A24(this, play, this->unk_160[this->unk_194]);
            ref_func_80B14A24(this, play, this->unk_160[this->unk_194]);
            ref_func_80B14F4C(this, play, false);
            ref_func_80B14B6C(this, play, this->unk_160[this->unk_194], 40);
            this->unk_194 = 1;
        } else if ((this->unk_19E > 10) && (this->dyna.actor.colChkInfo.health <= 10)) {
            ref_func_80B14A24(this, play, this->unk_160[this->unk_194]);
            ref_func_80B14A24(this, play, this->unk_160[this->unk_194]);
            ref_func_80B14B6C(this, play, this->unk_160[this->unk_194], 60);
            this->unk_194 = 2;
        }
        this->unk_19A = 0;
        this->dyna.actor.shape.yOffset -= 3.0f;
    }

    Math_ApproachZeroF(&this->dyna.actor.shape.yOffset, 0.8f, 100.0f);
    this->unk_19E = this->dyna.actor.colChkInfo.health;
}
