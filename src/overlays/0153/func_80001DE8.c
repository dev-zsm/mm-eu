// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_bean.h"

void ref_func_80938AD8(ObjBean* this, PlayState* play) {
    s32 pad;
    s32 sp30 = ref_func_80937468(this, play);

    ref_func_80937160(this);
    if (this->unk_1B2 == 25) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_PL_PLANT_GROW_BIG);
    }

    if (sp30 != 0) {
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    } else {
        DynaPoly_EnableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    }

    if (this->dyna.actor.xzDistToPlayer < 74.0f) {
        Player* player = GET_PLAYER(play);
        f32 sp28 = 74.0f - this->dyna.actor.xzDistToPlayer;
        f32 sin;
        f32 cos;

        if (sp28 > 8.0f) {
            sp28 = 8.0f;
        }

        sin = Math_SinS(this->dyna.actor.yawTowardsPlayer) * sp28;
        cos = Math_CosS(this->dyna.actor.yawTowardsPlayer) * sp28;

        player->actor.world.pos.x += sin;
        player->actor.world.pos.z += cos;
    }

    if ((this->unk_1B2 <= 0) && (sp30 == 0)) {
        ref_func_80936F04(this);
        ref_func_80938804(this);
    }
}
