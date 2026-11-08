// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_last_bwall.h"

void ref_func_80C184EC(BgLastBwall* this, PlayState* play) {
    f32 randVar;
    Vec3f spD0;
    Vec3f effectPosAndAccel;
    s32 var_v0;
    Vec3f effectVelocity;
    s32 i;

    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_NEW);
    Matrix_RotateXS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_RotateZS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
    for (i = 0; i < 30; i++) {
        switch (this->type) {
            case BGLASTBWALL_TYPE_0:
                spD0.x = 280.0f;
                spD0.y = Rand_Centered() * 160.0f + 320.0f;
                spD0.z = Rand_Centered() * 160.0f;
                Matrix_MultVec3f(&spD0, &effectPosAndAccel);
                Math_Vec3f_Sum(&this->dyna.actor.world.pos, &effectPosAndAccel, &effectPosAndAccel);
                break;

            case BGLASTBWALL_TYPE_1:
                spD0.x = Rand_Centered() * 160.0f;
                spD0.y = 400.0f;
                spD0.z = Rand_Centered() * 160.0f;
                Matrix_MultVec3f(&spD0, &effectPosAndAccel);
                Math_Vec3f_Sum(&this->dyna.actor.world.pos, &effectPosAndAccel, &effectPosAndAccel);
                break;
        }
        ref_func_800BBFB0(play, &effectPosAndAccel, 50.0f, 2, Rand_ZeroOne() * 120.0f + 20.0f,
                      Rand_ZeroOne() * 240.0f + 20.0f, 0);
        effectVelocity.x = Rand_ZeroOne() * 2.5f;
        effectVelocity.y = Rand_ZeroOne() * 2.5f + 1.0f;
        effectVelocity.z = Rand_ZeroOne() * 2.5f;
        randVar = Rand_ZeroOne();
        if (randVar < 0.2f) {
            var_v0 = 0x60;
        } else if (randVar < 0.6f) {
            var_v0 = 0x40;
        } else {
            var_v0 = 0x20;
        }
        EffectSsKakera_Spawn(play, &effectPosAndAccel, &effectVelocity, &effectPosAndAccel, -260, var_v0, 20, 0, 0, 10,
                             0, 0, 50, -1, OBJECT_LAST_OBJ, object_last_obj_DL_000098);
    }
}
