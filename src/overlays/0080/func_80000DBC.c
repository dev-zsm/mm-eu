// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

void EnBubble_Wait(EnBubble* this, PlayState* play) {
    if (EnBubble_IsPopped(this, play)) {
        this->explosionCountdown = ref_func_8089F59C(this);
        this->actionFunc = EnBubble_Pop;
    } else {
        EnBubble_Fly(this, play);
        this->actor.shape.yOffset = (this->modelHeight + 1.0f) * 16.0f;
        CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderSphere.base);
        CollisionCheck_SetOC(play, &play->colChkCtx, &this->colliderSphere.base);
    }
}
