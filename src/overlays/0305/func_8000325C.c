// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A262EC(ObjIceblock* this, PlayState* play) {
    s32 pad;
    f32 temp_f14;
    f32 temp_f18;
    Vec3f sp38;
    f32 temp;

    if (ref_func_80A25238(this) != -1) {
        ref_func_80A2541C(this, play);
    }

    if (this->stateTimer > 0) {
        this->stateTimer--;
    }

    if (this->stateTimer == -1) {
        if ((this->dyna.actor.velocity.y < 0.0f) && (this->dyna.actor.world.pos.y < this->unk_244) &&
            ((this->unk_244 - (600.0f * this->dyna.actor.scale.y)) <= this->dyna.actor.world.pos.y)) {
            ref_func_80A24BDC(this, play, 1.0f, 0.9f, 11);
            ref_func_80A24B74(this, play);
            this->stateTimer = 3;
        } else {
            this->stateTimer = 0;
        }
    } else if (this->stateTimer == 1) {
        ref_func_80A24BDC(this, play, 0.7f, 1.3f, 6);
        ref_func_80A24B74(this, play);
    }

    this->dyna.actor.velocity.y += 5.0f;
    if (this->dyna.actor.velocity.y > 3.0f) {
        this->dyna.actor.velocity.y = 3.0f;
    }

    temp = this->dyna.actor.velocity.y;
    this->dyna.actor.world.pos.y += temp;
    temp_f14 = this->dyna.actor.world.pos.y + (600.0f * this->dyna.actor.scale.y);
    if (this->unk_244 < (temp_f14 - 90.0f)) {
        ref_func_80A24B74(this, play);
        ref_func_80A26574(this);
    } else {
        if ((this->dyna.actor.velocity.y > 0.0f) && (temp_f14 < (this->unk_244 + 3.0f)) &&
            (this->unk_244 <= temp_f14)) {
            ref_func_80A24BDC(this, play, 0.8f, 1.0f, 11);
            ref_func_80A24B74(this, play);
        }

        sp38.x = this->dyna.actor.world.pos.x;
        sp38.y = (this->unk_244 - (600.0f * this->dyna.actor.scale.y)) + 90.0f;
        sp38.z = this->dyna.actor.world.pos.z;

        if (ref_func_80A246D8(this, play, &sp38)) {
            this->unk_1B0 |= 0x80;
        }
    }
}
