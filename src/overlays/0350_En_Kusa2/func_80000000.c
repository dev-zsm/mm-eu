// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5B160(EnKusa2* this, PlayState* play) {
    s32 i;
    s16 temp_s1;
    EnKusa2** ptr;
    EnKusa2* actor;

    if (this->unk_194[0] == NULL) {
        ptr = this->unk_194;
        actor = (EnKusa2*)Actor_SpawnAsChildAndCutscene(
            &play->actorCtx, play, ACTOR_EN_KUSA2, this->actor.world.pos.x, this->actor.world.pos.y,
            this->actor.world.pos.z, 0, Rand_Next() >> 0x10, 0, 1, this->actor.csId, this->actor.halfDaysBits, NULL);
        *ptr = actor;

        if (*ptr != NULL) {
            (*ptr)->actor.room = this->actor.room;
            (*ptr)->unk_1C0 = this;
        }
    }

    for (i = 1; i < ARRAY_COUNT(this->unk_194); i++) {
        temp_s1 = (i * 0x2000) - 0x2000;
        if (this->unk_194[i] == NULL) {
            ptr = &this->unk_194[i];
            actor = (EnKusa2*)Actor_SpawnAsChildAndCutscene(
                &play->actorCtx, play, ACTOR_EN_KUSA2, (Math_SinS(temp_s1) * 80.0f) + this->actor.world.pos.x,
                this->actor.world.pos.y, (Math_CosS(temp_s1) * 80.0f) + this->actor.world.pos.z, 0, Rand_Next() >> 0x10,
                0, 1, this->actor.csId, this->actor.halfDaysBits, NULL);
            *ptr = actor;
            if (*ptr != NULL) {
                (*ptr)->actor.room = this->actor.room;
                (*ptr)->unk_1C0 = this;
            }
        }
    }
}
