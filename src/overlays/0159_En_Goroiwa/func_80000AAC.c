// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_goroiwa.h"

s32 ref_func_8093F34C(EnGoroiwa* this) {
    s32 pad[3];
    Vec3s* temp_v0;
    f32 tempX;
    f32 tempZ;
    f32 x;
    f32 z;

    Math_StepToF(&this->actor.speed, ref_D_80942DFC[this->unk_1E4], 0.3f);
    Actor_UpdateVelocityWithGravity(&this->actor);
    temp_v0 = &this->pathPoints[this->unk_1D8];
    this->actor.velocity.y *= 0.97f;
    x = temp_v0->x;
    z = temp_v0->z;

    tempX = x - this->actor.world.pos.x;
    tempZ = z - this->actor.world.pos.z;

    if (SQ(this->actor.speed + 1.0f) < (SQ(tempX) + SQ(tempZ))) {
        this->actor.world.pos.x += this->actor.velocity.x;
        this->actor.world.pos.y += this->actor.velocity.y;
        this->actor.world.pos.z += this->actor.velocity.z;
        this->unk_1E5 &= ~0x40;
        return false;
    }

    this->actor.world.pos.x = x;
    this->actor.world.pos.y += this->actor.velocity.y;
    this->actor.world.pos.z = z;
    this->unk_1E5 |= 0x40;
    return true;
}
