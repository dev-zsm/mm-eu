// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_warp1.h"

void ref_func_808B9FD0(DoorWarp1* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Player* player2 = GET_PLAYER(play);

    if (this->unk_1CA != 0) {
        this->unk_1CA--;
        return;
    }

    if (!CutsceneManager_IsNext(play->playerCsIds[PLAYER_CS_ID_WARP_PAD_ENTRANCE])) {
        CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_WARP_PAD_ENTRANCE]);
    } else {
        CutsceneManager_Start(play->playerCsIds[PLAYER_CS_ID_WARP_PAD_ENTRANCE], NULL);
        AudioSfx_PlaySfx(NA_SE_EV_LINK_WARP, &player->actor.projectedPos, 4, &gSfxDefaultFreqAndVolScale,
                         &gSfxDefaultFreqAndVolScale, &gSfxDefaultReverb);
        Animation_ChangeImpl(&this->skelAnime, &gWarpCrystalAnim, 1.0f, Animation_GetLastFrame(&gWarpCrystalAnim),
                             Animation_GetLastFrame(&gWarpCrystalAnim), 2, 40.0f, 1);
        this->unk_1CA = 50;
        ref_D_808BC004 = player2->actor.world.pos.y;
        DoorWarp1_SetupAction(this, ref_func_808BA550);
    }
}
