// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9AE3C(BgHakuginPost* this, PlayState* play) {
    while (ref_D_80A9DDC0.count != 0) {
        ref_D_80A9DDC0.count--;
        Collider_DestroyCylinder(play, &ref_D_80A9DDC0.colliders[ref_D_80A9DDC0.count]);
    }
}
