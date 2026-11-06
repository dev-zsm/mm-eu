// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test7.h"

void EnTest7_WarpCsPart4(EnTest7* this, PlayState* play) {
    s32 pad;
    s32 temp = this->timer - 86;
    f32 temp_f0 = temp / (f32)(96 - 86);
    Vec3f featherPos;

    this->flags |= OWL_WARP_FLAGS_10;

    this->windCapsule.xzScale = (-0.15f * temp_f0) + 0.25f;
    this->windCapsule.yScale = (-0.3f * temp_f0) + 0.4f;
    this->windCapsule.yaw -= 0x2EE0;

    this->flags |= OWL_WARP_FLAGS_DRAW_LENS_FLARE;

    if (this->timer >= 96) {
        EnTest7_SetupAction(this, EnTest7_WarpCsPart5);
        this->flags &= ~OWL_WARP_FLAGS_10;
    }
    Math_Vec3f_Copy(&featherPos, &this->actor.world.pos);
    EnTest7_AddAndChooseFeather(this->feathers, &featherPos, true);
}
