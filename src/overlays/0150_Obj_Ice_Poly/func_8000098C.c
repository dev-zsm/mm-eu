// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_ice_poly.h"

void ref_func_80931EEC(ObjIcePoly* this, PlayState* play) {
    Vec3f spAC;
    Vec3f spA0;
    Vec3f sp94;
    f32 temp_f20;
    s32 i;
    s32 phi_v0;

    spAC.x = 0.0f;
    spAC.y = this->actor.scale.y;
    spAC.z = 0.0f;

    spA0.x = 0.0f;
    spA0.y = this->actor.scale.y;
    spA0.z = 0.0f;

    for (i = 0; i < 2; i++) {
        temp_f20 = Rand_ZeroOne();
        if (Rand_ZeroOne() < 0.5f) {
            phi_v0 = -1;
        } else {
            phi_v0 = 1;
        }
        sp94.x = (phi_v0 * (20.0f + (20.0f * temp_f20)) * this->actor.scale.x) + this->actor.world.pos.x;
        sp94.y = (Rand_ZeroOne() * this->actor.scale.y * 50.0f) + this->actor.world.pos.y;

        temp_f20 = Rand_ZeroOne();
        if (Rand_ZeroOne() < 0.5f) {
            phi_v0 = -1;
        } else {
            phi_v0 = 1;
        }
        sp94.z = (phi_v0 * (20.0f + (20.0f * temp_f20)) * this->actor.scale.x) + this->actor.world.pos.z;

        ref_func_800B0DE0(play, &sp94, &spA0, &spAC, &ref_D_80932378, &ref_D_8093237C,
                      ((Rand_ZeroOne() * 100.0f) + 350.0f) * this->actor.scale.x, this->actor.scale.x * 20.0f);
    }

    if (this->unk_14A != 0) {
        this->unk_14A--;
    }

    this->actor.scale.y = this->actor.params * 0.01f * (0.5f + (this->unk_14A * 0.0125f));
    this->unk_148 -= 6;

    if (this->unk_14A == 0) {
        CutsceneManager_Stop(this->actor.csId);
        if (this->switchFlag != OBJICEPOLY_SWITCH_FLAG_NONE) {
            Flags_SetSwitch(play, this->switchFlag);
        }
        Actor_Kill(&this->actor);
    }
}
