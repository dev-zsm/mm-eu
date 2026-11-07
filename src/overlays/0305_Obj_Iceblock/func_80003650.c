// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_iceblock.h"

void ref_func_80A266E0(ObjIceblock* this, PlayState* play) {
    f32 temp;
    s32 sp20;
    Actor* actor = &this->dyna.actor;

    Math_StepToF(&this->unk_2A8, (1.0f / 600.0f), (1.0f / 6000.0f));
    sp20 = Math_StepToF(&actor->scale.y, 0.0f, this->unk_2A8);
    temp = actor->scale.y * 10.0f * 300.0f;
    actor->shape.yOffset = temp;

    if (actor->scale.y < 0.075f) {
        actor->scale.x = Math_SinS(actor->scale.y * 218453.33f) * 0.1f;
        if (actor->scale.x < 0.0f) {
            actor->scale.x = 0.0f;
        }
        actor->scale.z = actor->scale.x;
    }

    if (ICEBLOCK_GET_ICEBERG(&this->dyna.actor)) {
        this->unk_2B4 = actor->scale.y;
        this->collider.dim.height = (s32)(actor->scale.y * 1230.0f) + 1;
        this->collider.dim.yShift = actor->scale.y * -1000.0f;
        this->collider.dim.radius = actor->scale.x * 290.0f;
    }

    ref_func_80A2508C(this, play);

    if (sp20) {
        Actor_Kill(&this->dyna.actor);
    }
}
