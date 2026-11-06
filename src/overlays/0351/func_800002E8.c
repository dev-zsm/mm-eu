// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_spout_fire.h"

void ref_func_80A60E08(BgSpoutFire* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f sp30;
    f32 cos;
    f32 sin;

    Actor_WorldToActorCoords(&this->actor, &sp30, &player->actor.world.pos);
    sp30.x = CLAMP(sp30.x, -74.25f, 74.25f);
    if (this->timer == 0) {
        if (sp30.z > 0.0f) {
            sp30.z = -25.0f;
            this->timer = -1;
        } else {
            sp30.z = 25.0f;
            this->timer = 1;
        }
    } else {
        sp30.z = this->timer * 25.0f;
    }
    sin = Math_SinS(this->actor.shape.rot.y);
    cos = Math_CosS(this->actor.shape.rot.y);
    this->collider.dim.pos.x = this->actor.world.pos.x + (sp30.x * cos) + (sp30.z * sin);
    this->collider.dim.pos.z = this->actor.world.pos.z - (sp30.x * sin) + (sp30.z * cos);
}
