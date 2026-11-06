// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_hugebombiwa.h"

s32 ref_func_80A54A0C(ObjHugebombiwa* this) {
    static f32 ref_D_80A55D74[] = { 62500.0f, 108900.0f };
    s32 sp2C;
    Actor* ac;
    s32 params;
    Vec3f sp20;

    if ((this->collider.base.acFlags & AC_HIT) && (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x80000000)) {
        ac = this->collider.base.ac;
        params = ENHUGEBOMBIWA_GET_100(&this->actor);

        sp20.x = this->actor.world.pos.x;
        sp20.y = this->actor.world.pos.y + 50.0f;
        sp20.z = this->actor.world.pos.z;
        if (ac != NULL) {
            if (Math3D_Vec3fDistSq(&sp20, &ac->world.pos) < ref_D_80A55D74[params]) {
                return true;
            }
        }
    }
    return false;
}
