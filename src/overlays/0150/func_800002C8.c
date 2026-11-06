// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ice_poly.h"

void ref_func_80931828(ObjIcePoly* this, PlayState* play) {
    static Color_RGBA8 ref_D_80932380 = { 170, 255, 255, 255 };
    static Color_RGBA8 ref_D_80932384 = { 0, 50, 100, 255 };
    static Vec3f ref_D_80932388 = { 0.0f, -1.0f, 0.0f };
    f32 temp;
    Vec3f spA0;
    Vec3f sp94;
    f32 sp90;
    s32 i;
    CollisionPoly* sp88;

    spA0.x = this->actor.world.pos.x;
    spA0.y = (this->colliders1[0].dim.height * 2) + this->actor.world.pos.y;
    spA0.z = this->actor.world.pos.z;

    sp90 = BgCheck_EntityRaycastFloor1(&play->colCtx, &sp88, &spA0);
    if (sp90 < this->actor.world.pos.y) {
        sp90 = this->actor.world.pos.y;
    }
    temp = spA0.y - sp90;

    for (i = 0; i < 30; i++) {
        sp94.x = Rand_CenteredFloat(12.0f);
        sp94.y = Rand_ZeroFloat(15.0f);
        sp94.z = Rand_CenteredFloat(12.0f);

        spA0.x = (this->colliders1[0].dim.radius * (sp94.x * (1.0f / 12))) + this->actor.world.pos.x;
        spA0.z = (this->colliders1[0].dim.radius * (sp94.z * (1.0f / 12))) + this->actor.world.pos.z;
        spA0.y = Rand_ZeroFloat(temp) + sp90;
        EffectSsEnIce_Spawn(play, &spA0, (Rand_ZeroFloat(0.4f) + 0.3f) * this->actor.scale.x, &sp94, &ref_D_80932388,
                            &ref_D_80932380, &ref_D_80932384, 40);
    }
}
