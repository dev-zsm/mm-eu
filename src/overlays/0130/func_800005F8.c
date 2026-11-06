// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FA3F8(EnRr* this, Player* player) {
    s32 i;

    this->unk_1EA = 100;
    this->unk_1FC = 20;
    this->collider1.base.ocFlags1 &= ~OC1_TYPE_PLAYER;
    this->actor.flags &= ~ACTOR_FLAG_ATTENTION_ENABLED;
    this->unk_1F0 = 8;
    this->unk_1E1 = 0;
    this->actor.speed = 0.0f;
    this->unk_218 = 0.0f;
    this->unk_210 = 0.0f;
    this->unk_204 = 0.15f;
    this->unk_20C = 0x200;
    this->unk_1F6 = 5000;

    for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
        this->unk_324[i].unk_04 = 0.0f;
        this->unk_324[i].unk_0C = 1.0f;
        this->unk_324[i].unk_14 = 0;
        this->unk_324[i].unk_18 = 0;
    }

    this->actionFunc = ref_func_808FB1C0;
    Actor_PlaySfx(&this->actor, NA_SE_EN_SUISEN_DRINK);
}
