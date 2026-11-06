// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

s32 EnBubble_IsPopped(EnBubble* this, PlayState* play) {
    if ((DECR(this->timer) != 0) || (this->actionFunc == EnBubble_Pop)) {
        return false;
    }
    if (this->colliderSphere.base.ocFlags2 & OC2_HIT_PLAYER) {
        this->colliderSphere.base.ocFlags2 &= ~OC2_HIT_PLAYER;
        EnBubble_DamagePlayer(this, play);
        this->timer = 8;
        return true;
    }
    return ref_func_8089FF30(this);
}
