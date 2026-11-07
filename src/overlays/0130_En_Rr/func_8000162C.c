// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_rr.h"

void ref_func_808FB42C(EnRr* this, PlayState* play) {
    s32 pad;
    s32 i;
    EnRrStruct* ptr;
    f32 temp_f20;

    this->actor.colorFilterTimer = 40;
    if (this->unk_1E4 < 40) {
        for (i = 0; i < ARRAY_COUNT(this->unk_324); i++) {
            ptr = &this->unk_324[i];
            Math_StepToF(&ptr->unk_04, (i + 59) - (this->unk_1E4 * 25.0f), 50.0f);
            ptr->unk_0C = (SQ((f32)(4 - i)) * this->unk_1E4 * 0.003f) + 1.0f;
        }
        return;
    }

    if (this->unk_1E4 >= 95) {
        if (this->unk_1E2 != 0) {
            Item_DropCollectible(play, &this->actor.world.pos, ITEM00_SHIELD_HERO);
        }
        Item_DropCollectibleRandom(play, &this->actor, &this->actor.world.pos, 0x90);
        Actor_Kill(&this->actor);
        return;
    }

    if (this->unk_1E4 == 88) {
        Vec3f sp74;

        sp74.x = this->actor.world.pos.x;
        sp74.y = this->actor.world.pos.y + 20.0f;
        sp74.z = this->actor.world.pos.z;
        ref_func_800B3030(play, &sp74, &gZeroVec3f, &gZeroVec3f, 100, 0, 0);
        SoundSource_PlaySfxAtFixedWorldPos(play, &sp74, 11, NA_SE_EN_EXTINCT);
    } else {
        temp_f20 = this->actor.scale.y * 66.66667f;

        Math_StepToF(&this->actor.scale.x, 0.0f, this->unk_214);
        Math_StepToF(&this->unk_214, 0.001f * temp_f20, 0.00001f * temp_f20);
        this->actor.scale.z = this->actor.scale.x;
    }
}
