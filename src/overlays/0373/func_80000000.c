// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_test6.h"

void EnTest6_SetupCutscene(EnTest6* this, PlayState* play) {
    s32 i;
    Player* player = GET_PLAYER(play);
    s32 ammoFlags;
    f32 yOffset;

    this->actor.home.pos = player->actor.world.pos;
    this->actor.home.rot = player->actor.shape.rot;

    switch (SOTCS_GET_OCARINA_MODE(&this->actor)) {
        case OCARINA_MODE_APPLY_INV_SOT_FAST:
        case OCARINA_MODE_APPLY_INV_SOT_SLOW:
            EnTest6_SetupInvertedSoTCutscene(this, play);
            CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
            break;

        case OCARINA_MODE_APPLY_DOUBLE_SOT:
            EnTest6_SetupDoubleSoTCutscene(this, play);
            CutsceneManager_Queue(play->playerCsIds[PLAYER_CS_ID_SONG_WARP]);
            break;

        default: 
            ammoFlags = 0;
            yOffset = -900.0f;

            if (CHECK_EVENTINF(EVENTINF_THREEDAYRESET_LOST_RUPEES)) {
                for (i = 0; i < 6; i++) {
                    sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type =
                        SOTCS_AMMO_DROP_RUPEE_GREEN;
                }
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type =
                    SOTCS_AMMO_DROP_RUPEE_GREEN;
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_RUPEE_BLUE;
                ammoFlags |= SOTCS_AMMO_FLAG_RUPEE;
            }

            if (CHECK_EVENTINF(EVENTINF_THREEDAYRESET_LOST_ARROW_AMMO)) {
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_ARROWS;
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_ARROWS;
                if (!(ammoFlags & SOTCS_AMMO_FLAG_RUPEE)) {
                    sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_ARROWS;
                    sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_ARROWS;
                }
                ammoFlags |= SOTCS_AMMO_FLAG_ARROW;
            }

            if (CHECK_EVENTINF(EVENTINF_THREEDAYRESET_LOST_BOMB_AMMO)) {
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_BOMB;
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_BOMB;
                if (!(ammoFlags & SOTCS_AMMO_FLAG_RUPEE)) {
                    sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_BOMB;
                    sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_BOMB;
                }
                ammoFlags |= SOTCS_AMMO_FLAG_BOMB;
            }

            if (CHECK_EVENTINF(EVENTINF_THREEDAYRESET_LOST_NUT_AMMO)) {
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_DEKU_NUT;
                if (!(ammoFlags & (SOTCS_AMMO_FLAG_ARROW | SOTCS_AMMO_FLAG_BOMB | SOTCS_AMMO_FLAG_RUPEE))) {
                    sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type =
                        SOTCS_AMMO_DROP_DEKU_NUT;
                }
                ammoFlags |= SOTCS_AMMO_FLAG_NUT;
            }

            if (CHECK_EVENTINF(EVENTINF_THREEDAYRESET_LOST_STICK_AMMO)) {
                sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type = SOTCS_AMMO_DROP_DEKU_STICK;
                if (!(ammoFlags & (SOTCS_AMMO_FLAG_ARROW | SOTCS_AMMO_FLAG_BOMB | SOTCS_AMMO_FLAG_RUPEE))) {
                    sSoTCsAmmoDrops[(s32)(Rand_ZeroOne() * ARRAY_COUNT(sSoTCsAmmoDrops))].type =
                        SOTCS_AMMO_DROP_DEKU_STICK;
                }
            }

            for (i = 0; i < ARRAY_COUNT(sSoTCsAmmoDrops); i++) {
                sSoTCsAmmoDrops[i].pos.x = ((2.0f * Rand_ZeroOne()) - 1.0f) * 80.0f;
                sSoTCsAmmoDrops[i].pos.z = ((2.0f * Rand_ZeroOne()) - 1.0f) * 80.0f;
                sSoTCsAmmoDrops[i].pos.y = (((2.0f * Rand_ZeroOne()) - 1.0f) * 40.0f) + yOffset;
                sSoTCsAmmoDrops[i].scale = -10.0f;
                if (sSoTCsAmmoDrops[i].type <= SOTCS_AMMO_DROP_DEKU_STICK) {
                    sSoTCsAmmoDrops[i].draw = EnTest6_DrawAmmoDropDefault;
                } else {
                    sSoTCsAmmoDrops[i].draw = EnTest6_DrawAmmoDropRupee;
                }
                yOffset += 50.0f;
            }
            break;
    }
}
