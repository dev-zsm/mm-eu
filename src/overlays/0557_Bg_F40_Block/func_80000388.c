// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_block.h"

s32 ref_func_80BC3D08(BgF40Block* this, PlayState* play, s32 arg2) {
    CollisionPoly* sp54;
    Vec3f sp48;
    Vec3f sp3C;
    Vec3f sp30;

    if (this->unk_168 == 6) {
        return false;
    }

    if (arg2) {
        sp48.x =
            (ref_D_80BC4620[this->unk_168].x * ((800.0f * this->dyna.actor.scale.x) - (this->dyna.actor.speed * 0.5f))) +
            this->dyna.actor.world.pos.x;
        sp48.y =
            (ref_D_80BC4620[this->unk_168].y * ((800.0f * this->dyna.actor.scale.y) - (this->dyna.actor.speed * 0.5f))) +
            this->dyna.actor.world.pos.y;
        sp48.z =
            (ref_D_80BC4620[this->unk_168].z * ((800.0f * this->dyna.actor.scale.z) - (this->dyna.actor.speed * 0.5f))) +
            this->dyna.actor.world.pos.z;

        sp3C.x = (ref_D_80BC4620[this->unk_168].x * this->dyna.actor.speed) + sp48.x;
        sp3C.y = (ref_D_80BC4620[this->unk_168].y * this->dyna.actor.speed) + sp48.y;
        sp3C.z = (ref_D_80BC4620[this->unk_168].z * this->dyna.actor.speed) + sp48.z;
    } else {
        sp3C.x = (ref_D_80BC4620[this->unk_168].x * 800.0f * this->dyna.actor.scale.x) + this->dyna.actor.world.pos.x;
        sp3C.y = (ref_D_80BC4620[this->unk_168].y * 800.0f * this->dyna.actor.scale.y) + this->dyna.actor.world.pos.y;
        sp3C.z = (ref_D_80BC4620[this->unk_168].z * 800.0f * this->dyna.actor.scale.z) + this->dyna.actor.world.pos.z;

        sp48.x = sp3C.x - (ref_D_80BC4620[this->unk_168].x * this->dyna.actor.speed * 1.5f);
        sp48.y = sp3C.y - (ref_D_80BC4620[this->unk_168].y * this->dyna.actor.speed * 1.5f);
        sp48.z = sp3C.z - (ref_D_80BC4620[this->unk_168].z * this->dyna.actor.speed * 1.5f);
    }

    if (BgCheck_AnyLineTest1(&play->colCtx, &sp48, &sp3C, &sp30, &sp54, true)) {
        if (!arg2) {
            this->dyna.actor.world.pos.x -= sp3C.x - sp30.x;
            this->dyna.actor.world.pos.y -= sp3C.y - sp30.y;
            this->dyna.actor.world.pos.z -= sp3C.z - sp30.z;
        }
        return true;
    }

    return false;
}
