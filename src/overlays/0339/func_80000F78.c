// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_mkk.h"

void ref_func_80A4EE48(EnMkk* this, PlayState* play) {
    if (this->unk_14E > 0) {
        this->unk_14E--;
        if (this->unk_14E == 0) {
            this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        }
    } else if ((this->actor.xzDistToPlayer < this->unk_178) && (Player_GetMask(play) != PLAYER_MASK_STONE)) {
        this->actor.update = EnMkk_Update;
        this->actor.draw = EnMkk_Draw;
        this->actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        ref_func_80A4E0CC(this);
    }
}
