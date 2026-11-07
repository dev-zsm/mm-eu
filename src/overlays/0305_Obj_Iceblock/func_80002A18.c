// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A25AA8(ObjIceblock* this, PlayState* play) {
    s32 pad[2];
    f32 sp24;
    s32 temp = ref_func_80A236D4(this, &this->dyna.actor.home.pos);

    if (this->stateTimer > 0) {
        this->stateTimer--;
        return;
    }

    if (temp) {
        sp24 = this->dyna.actor.scale.y * 300.0f;
        ref_func_80A23D08(this, play);
        if (sp24 < (this->dyna.actor.world.pos.y - this->dyna.actor.floorHeight)) {
            ref_func_80A25BA0(this);
        } else {
            ref_func_80A25C5C(this);
        }

        this->dyna.actor.world.pos.y -= sp24;
        this->dyna.actor.shape.yOffset = 300.0f;
        this->unk_248.y += sp24;

        if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor)) {
            this->collider.dim.yShift = -69;
        } else {
            this->collider.dim.yShift = 0;
        }
        this->unk_1B0 |= 0x100;
    }
}
