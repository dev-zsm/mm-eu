// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_balance.h"

s32 ref_func_80B82454(BgDblueBalance* this, PlayState* play) {
    s32 pad;
    s32 sp58 = true;
    BgDblueBalance* balance;
    Vec3f sp48;
    Vec3f sp3C;

    Matrix_Translate(this->dyna.actor.world.pos.x, this->dyna.actor.world.pos.y, this->dyna.actor.world.pos.z,
                     MTXMODE_NEW);
    Matrix_RotateYS(this->dyna.actor.shape.rot.y, MTXMODE_APPLY);
    Matrix_RotateZS(this->dyna.actor.shape.rot.z, MTXMODE_APPLY);

    sp48.x = -138.28f;
    sp48.y = 0.0f;
    sp48.z = 0.0f;

    Matrix_MultVec3f(&sp48, &sp3C);

    this->unk_15C = (BgDblueBalance*)Actor_Spawn(&play->actorCtx, play, ACTOR_BG_DBLUE_BALANCE, sp3C.x, sp3C.y, sp3C.z,
                                                 0, this->dyna.actor.shape.rot.y, 0, 0x100);
    if (this->unk_15C == NULL) {
        sp58 = false;
    } else {
        balance = this->unk_15C;
        balance->unk_164 = this;
    }

    sp48.x = 138.28f;
    Matrix_MultVec3f(&sp48, &sp3C);

    this->unk_160 = (BgDblueBalance*)Actor_Spawn(&play->actorCtx, play, ACTOR_BG_DBLUE_BALANCE, sp3C.x, sp3C.y, sp3C.z,
                                                 0, this->dyna.actor.shape.rot.y, 0, 0x200);
    if (this->unk_160 == NULL) {
        sp58 = false;
    } else {
        balance = this->unk_160;
        balance->unk_164 = this;
    }

    return sp58;
}
