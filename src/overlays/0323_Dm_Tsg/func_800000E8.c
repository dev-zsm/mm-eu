// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_tsg.h"

void DmTsg_Update(Actor* thisx, PlayState* play) {
    DmTsg* this = (DmTsg*)thisx;
    s32 cueChannel;
    s16 i;

    for (i = 0; i < DMTSG_UNK_SIZE; i++) {
        this->unk_5F8[i] = (Math_SinS((i % 16U) * this->unk_854) * 60.0f) + 120.0f;
        this->unk_148[i].x = Math_CosS(this->unk_78C[i]) * this->unk_5F8[i];
        this->unk_148[i].y = this->unk_788 + (i * 16);
        this->unk_148[i].z = Math_SinS(this->unk_78C[i]) * this->unk_5F8[i];
        this->unk_78C[i] += this->unk_856[i];
    }

    this->canDraw = false;
    this->unk_854 += 40;

    if (Cutscene_IsCueInChannel(play, CS_CMD_ACTOR_CUE_514)) {
        cueChannel = Cutscene_GetCueChannel(play, CS_CMD_ACTOR_CUE_514);
        if (play->csCtx.actorCues[cueChannel]->id != 1) {
            this->canDraw = true;
        }
        Cutscene_ActorTranslateAndYaw(&this->actor, play, cueChannel);
    }
}
