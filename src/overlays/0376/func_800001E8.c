// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9AEB8(BgHakuginPost* this, PlayState* play, BgHakuginPostUnkStruct* unkStruct) {
    s32 i;

    for (i = 0; i < unkStruct->count; i++) {
        ColliderCylinder* collider = unkStruct->unk_0000[i].collider;

        if ((collider != NULL) && (unkStruct->unk_0000[i].unk_34 == 1)) {
            collider->dim.pos.x = unkStruct->unk_0000[i].unk_14.x + this->dyna.actor.home.pos.x;
            collider->dim.pos.y = unkStruct->unk_0000[i].unk_14.y + this->unk_16C;
            collider->dim.pos.z = unkStruct->unk_0000[i].unk_14.z + this->dyna.actor.home.pos.z;
            CollisionCheck_SetAC(play, &play->colChkCtx, &collider->base);
        }
    }
}
