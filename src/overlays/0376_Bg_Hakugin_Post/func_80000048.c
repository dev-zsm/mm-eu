// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9AD18(BgHakuginPost* this, PlayState* play, BgHakuginPostUnkStruct* unkStruct) {
    s32 i;

    for (i = 0; i < unkStruct->count; i++) {
        BgHakuginPostUnkStruct3* unkStruct3 = &ref_D_80A9D880[unkStruct->unk_0000[i].unk_00];

        if ((unkStruct3->unk_04) && (ref_D_80A9DDC0.count < 8)) {
            ColliderCylinder* collider = &ref_D_80A9DDC0.colliders[ref_D_80A9DDC0.count];

            Collider_InitCylinder(play, collider);
            Collider_SetCylinder(play, collider, &this->dyna.actor, &sCylinderInit);
            collider->dim.height = (s32)unkStruct3->unk_00 - 40;
            unkStruct->unk_0000[i].collider = collider;
            ref_D_80A9DDC0.count++;
        }
    }
}
