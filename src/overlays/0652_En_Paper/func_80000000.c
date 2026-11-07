// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_paper.h"

void EnPaper_Init(Actor* thisx, PlayState* play) {
    EnPaper* this = (EnPaper*)thisx;

    Actor_SetScale(&this->actor, 0.01f);
    this->timer = 70;
    this->windForce = sUnitVecZ;
    Actor_UpdateBgCheckInfo(play, &this->actor, 0.0f, 0.0f, 0.0f, UPDBGCHECKINFO_FLAG_4);
    EnPaper_SetupSpreadConfettiGroup(this);
}
