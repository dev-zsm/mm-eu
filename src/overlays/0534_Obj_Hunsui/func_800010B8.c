// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hunsui.h"

void ref_func_80B9D508(ObjHunsui* this, PlayState* play) {
    if (((this->unk_160 == OBJHUNSUI_F000_5) || (this->unk_160 == OBJHUNSUI_F000_6)) &&
        (this->unk_16C != play->roomCtx.curRoom.num) && (this->unk_16C != play->roomCtx.prevRoom.num) &&
        (this->unk_16D != play->roomCtx.curRoom.num) && (this->unk_16D != play->roomCtx.prevRoom.num)) {
        switch (this->unk_160) {
            case OBJHUNSUI_F000_5:
                ref_D_80B9DED8.unk_01 = 0;
                break;

            case OBJHUNSUI_F000_6:
                ref_D_80B9DED8.unk_02 = 0;
                break;
        }
        Actor_Kill(&this->dyna.actor);
        return;
    }

    ref_func_80B9C5E8(this, play);
    ref_func_80B9D094(this, play);

    if (((this->unk_160 == OBJHUNSUI_F000_5) || (this->unk_160 == OBJHUNSUI_F000_6)) &&
        (play->roomCtx.curRoom.num == 8)) {
        ref_func_80B9D334(this, play);
    }

    if (!(this->unk_172 & 0x40)) {
        Math_SmoothStepToF(&this->unk_178, this->unk_174, 0.6f, 10.5f, 0.05f);
    }

    this->dyna.actor.world.pos.y = this->unk_198 + (this->dyna.actor.home.pos.y + this->unk_178);

    if ((this->unk_160 == OBJHUNSUI_F000_6) || (this->unk_160 == OBJHUNSUI_F000_5)) {
        this->unk_1AC += -10.0f + (1.8f * (this->dyna.actor.world.pos.y - this->dyna.actor.prevPos.y));
        this->unk_1B0 += -8.0f + (0.9f * (this->dyna.actor.world.pos.y - this->dyna.actor.prevPos.y));
    }

    if (!(this->unk_172 & 1) && !ref_func_80B9C450(play, this->switchFlag, this->unk_164)) {
        this->csId = this->csIdList[0];
        this->unk_172 |= 0x40;
        ref_func_80B9D0FC(this, play);
    }
}
