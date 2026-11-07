// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_boom.h"

void EnBoom_Destroy(Actor* thisx, PlayState* play) {
    EnBoom* this = (EnBoom*)thisx;
    Player* player = GET_PLAYER(play);
    Actor* otherZoraBoomerangActor;

    if (player != NULL) {
        Effect_Destroy(play, this->effectIndex);
        Collider_DestroyQuad(play, &this->collider);

        otherZoraBoomerangActor = this->actor.child;
        if (otherZoraBoomerangActor != NULL) {
            otherZoraBoomerangActor->parent = NULL;
            player->zoraBoomerangActor = otherZoraBoomerangActor;
        } else {
            otherZoraBoomerangActor = this->actor.parent;
            if (otherZoraBoomerangActor != NULL) {
                otherZoraBoomerangActor->child = NULL;
            } else {
                player->zoraBoomerangActor = NULL;
                player->stateFlags1 &= ~PLAYER_STATE1_ZORA_BOOMERANG_THROWN;
            }
        }
        player->stateFlags3 |= PLAYER_STATE3_ZORA_BOOMERANG_CAUGHT;
    }
}
