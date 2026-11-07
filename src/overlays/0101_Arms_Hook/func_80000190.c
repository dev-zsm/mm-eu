// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_arms_hook.h"

s32 ArmsHook_CheckForCancel(ArmsHook* this) {
    Player* player = (Player*)this->actor.parent;

    if (Player_IsHoldingHookshot(player)) {
        if ((player->itemAction != player->heldItemAction) || (player->actor.flags & ACTOR_FLAG_TALK) ||
            (player->stateFlags1 & (PLAYER_STATE1_DEAD | PLAYER_STATE1_4000000))) {
            this->timer = 0;
            ArmsHook_DetachFromActor(this);
            Math_Vec3f_Copy(&this->actor.world.pos, &player->rightHandWorld.pos);
            return 1;
        }
    }
    return 0;
}
