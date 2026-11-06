// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9CCA0(BgHakuginPost* this, PlayState* play) {
    if (this->unk_174 != 0) {
        ref_func_80A9D1E0(this, ref_func_80A9CD00, (this->unk_164 - this->dyna.actor.home.pos.y) + 100.0f, 60,
                      this->dyna.actor.csId);
    }
}
