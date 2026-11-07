// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

s32 ref_func_80ABCC00(BgHakuginBombwall* this, PlayState* play) {
    if (this->collider.base.acFlags & AC_HIT) {
        if (this->collider.elem.acHitElem->atDmgInfo.dmgFlags & 8) {
            if (this->collider.base.ac != NULL) {
                Actor* thisx = &this->dyna.actor;

                if (Math3D_Vec3fDistSq(&thisx->world.pos, &this->collider.base.ac->world.pos) <
                    ref_D_80ABCFC0[BGHAKUGIN_BOMBWALL_100(thisx)].unk_1C) {
                    SoundSource_PlaySfxAtFixedWorldPos(play, &thisx->world.pos, 50, NA_SE_EV_WALL_BROKEN);
                    return true;
                }
            }
        } else if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 50, NA_SE_EV_WALL_BROKEN);
            return true;
        }
    }
    return false;
}
