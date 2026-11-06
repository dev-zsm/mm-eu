// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_bombwall.h"

s32 ref_func_80ABCB5C(BgHakuginBombwall* this, PlayState* play) {
    if (this->collider.base.acFlags & AC_HIT) {
        if (this->collider.base.ac != NULL) {
            Actor* thisx = &this->dyna.actor;

            if (Math3D_Vec3fDistSq(&thisx->world.pos, &this->collider.base.ac->world.pos) <
                ref_D_80ABCFC0[BGHAKUGIN_BOMBWALL_100(thisx)].unk_1C) {
#if MM_VERSION >= N64_US
                SoundSource_PlaySfxAtFixedWorldPos(play, &thisx->world.pos, 60, NA_SE_EV_WALL_BROKEN);
#endif
                return true;
            }
        }
    }
    return false;
}
