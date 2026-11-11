// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_bubble.h"

void EnBubble_DamagePlayer(EnBubble* this, PlayState* play) {
    play->damagePlayer(play, -this->colliderSphere.elements[0].base.atDmgInfo.damage);
    ref_func_800B8E1C(play, &this->actor, 6.0f, this->actor.yawTowardsPlayer, 6.0f);
}
