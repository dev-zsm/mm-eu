// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikninside.h"

void ref_func_80C072D0(BgIkninside* this, PlayState* play) {
    s16 altitude;
    s16 azimuth;
    Vec3f pos;
    Vec3f velocity;
    f32 speed;
    s32 i;

    if (this->collider.base.acFlags & AC_HIT) {
        if ((this->collider.elem.acHitElem != NULL) &&
            (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 0x80000000)) {
            for (i = 0; i < 20; i++) {
                altitude = Rand_S16Offset(0x1800, 0x2800);
                azimuth = Rand_Next() >> 0x10;
                speed = Rand_ZeroFloat(3.0f) + 8.0f;
                velocity.x = speed * Math_CosS(altitude) * Math_SinS(azimuth);
                velocity.y = speed * Math_SinS(altitude) + Rand_ZeroFloat(5.0f);
                velocity.z = speed * Math_CosS(altitude) * Math_CosS(azimuth);
                pos.x = Rand_ZeroFloat(10.0f) * velocity.x + this->dyna.actor.world.pos.x;
                pos.y = Rand_ZeroFloat(1.0f) * velocity.y + this->dyna.actor.world.pos.y;
                pos.z = Rand_ZeroFloat(10.0f) * velocity.z + this->dyna.actor.world.pos.z;
                EffectSsHahen_Spawn(play, &pos, &velocity, &ref_D_80C076D4, 0, 30, OBJECT_IKNINSIDE_OBJ, 25,
                                    ref_D_80C076A0[i & 1]);
            }
            Flags_SetSwitch(play, DMIKNINSIDE_GET_SWITCH_FLAG(&this->dyna.actor));
            this->actionFunc = ref_func_80C07230;
            this->dyna.actor.draw = NULL;
            DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
        } else {
            this->timer = 20;
        }
    }
    if (this->timer > 0) {
        if ((this->timer % 2) != 0) {
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y - 1.0f;
        } else {
            this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y;
        }
        this->timer--;
    } else {
        this->timer = 0;
        this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y;
    }
    CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
}
