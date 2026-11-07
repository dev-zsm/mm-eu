// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ref_func_80B9CE64(ObjHunsui* this, PlayState* play) {
    s32 sp2C;
    f32 sins;

    if (!(this->unk_172 & 2)) {
        ref_func_80B9C5E8(this, play);
    }

    this->unk_18A += 0x71C;
    Math_SmoothStepToF(&this->unk_190, this->unk_194, 1.0f, 0.2f, 0.01f);

    sp2C = ref_func_80B9C450(play, this->switchFlag, this->unk_164);

    if (!(this->unk_172 & 1)) {
        if (sp2C != this->unk_180) {
            this->csId = this->csIdList[0];
            this->unk_172 |= 0x40;
        }
    }

    if ((this->unk_172 & 1) || (sp2C != 0)) {
        this->unk_172 &= ~2;
        if (this->unk_186 == 0) {
            this->unk_172 |= 0x10;
            this->unk_174 = 240.0f;
            if (this->unk_178 == 240.0f) {
                if (this->unk_188++ > 40) {
                    this->unk_188 = 0;
                    this->unk_186 = 1;
                    this->unk_194 = 0.0f;
                } else {
                    this->unk_194 = 8.0f;
                }
            }
        } else {
            this->unk_174 = 30.0f;
            if (this->unk_178 == 30.0f) {
                if (this->unk_188++ > 40) {
                    this->unk_188 = 0;
                    this->unk_186 = 0;
                    this->unk_194 = 0.0f;
                } else {
                    this->unk_194 = 8.0f;
                }
            }
        }
    } else {
        this->unk_174 = -30.0f;
        if (this->unk_178 == -30.0f) {
            this->unk_172 &= ~0x10;
            this->unk_172 |= 2;
        }
    }

    sins = Math_SinS(this->unk_18A);
    this->unk_198 = sins * this->unk_190;
    if (!(this->unk_172 & 0x40)) {
        Math_SmoothStepToF(&this->unk_178, this->unk_174, 0.6f, 10.5f, 0.05f);
    }

    this->dyna.actor.world.pos.y = this->unk_198 + (this->dyna.actor.home.pos.y + this->unk_178);
    this->unk_180 = sp2C;
}
