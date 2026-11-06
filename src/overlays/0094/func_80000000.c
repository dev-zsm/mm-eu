// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_m_thunder.h"

void EnMThunder_UnkType_Setup(EnMThunder* this, PlayState* play) {
    Player* player = GET_PLAYER(play);

    this->actor.update = EnMThunder_UnkType_Update;
    this->isCharging = false;
    this->subtype = ENMTHUNDER_SUBTYPE_SPIN_REGULAR;
    this->scaleTarget = 2;
    this->actionFunc = EnMThunder_UnkType_Attack;
    this->timer = 8;
    this->lightColorFrac = 1.0f;
    AudioSfx_PlaySfx(NA_SE_IT_ROLLING_CUT_LV1, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                     &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
    this->actor.child = NULL;
}
