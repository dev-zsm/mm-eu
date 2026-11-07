// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_cha.h"

void EnCha_Update(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnCha* this = (EnCha*)thisx;

    CollisionCheck_SetOC(play, &play->colChkCtx, &this->collider.base);
    this->actionFunc(this, play);
    if ((this->actor.shape.rot.z > -0x1F40) && (this->actor.shape.rot.z < 0x1F40)) {
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->collider.base);
    }
}
