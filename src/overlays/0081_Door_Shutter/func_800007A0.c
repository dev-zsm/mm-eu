// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void ref_func_808A1090(DoorShutter* this, PlayState* play) {
    if (this->slidingDoor.unk_15C != 0) {
        DoorShutter_SetupAction(this, ref_func_808A1684);
        this->slidingDoor.dyna.actor.velocity.y = 0.0f;
        if (this->unk_166 != 0) {
            Flags_SetSwitch(play, DOORSHUTTER_GET_SWITCH_FLAG(&this->slidingDoor.dyna.actor));
            if (this->doorType != DOORSHUTTER_TYPE_BOSS_DOOR) {
                DUNGEON_KEY_COUNT(gSaveContext.mapIndex) = DUNGEON_KEY_COUNT(gSaveContext.mapIndex) - 1;
                Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_CHAIN_KEY_UNLOCK);
            } else {
                Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_CHAIN_KEY_UNLOCK_B);
            }
        }
    } else {
        s32 doorDirection = ref_func_808A0E28(this, play);

        if (doorDirection != 0) {
            Player* player = GET_PLAYER(play);

            player->doorType = PLAYER_DOORTYPE_SLIDING;
            player->doorDirection = doorDirection;
            player->doorActor = &this->slidingDoor.dyna.actor;

            if (this->unk_163 == 7) {
                player->doorTimer = 12;
            } else {
                player->doorTimer = 0;
            }

            if (this->doorType == DOORSHUTTER_TYPE_6) {
                if (gSaveContext.save.saveInfo.playerData.healthCapacity <
                    (DOORSHUTTER_GET_1F(&this->slidingDoor.dyna.actor) * 0x10)) {
                    player->doorType = PLAYER_DOORTYPE_TALKING;
                    this->slidingDoor.dyna.actor.textId = 0x14FC;
                }
            } else if (this->unk_166 != 0) {
                if (this->doorType == DOORSHUTTER_TYPE_BOSS_DOOR) {
                    if (!CHECK_DUNGEON_ITEM(DUNGEON_BOSS_KEY, gSaveContext.mapIndex)) {
                        player->doorType = PLAYER_DOORTYPE_TALKING;
                        this->slidingDoor.dyna.actor.textId = 0x1803;
                    }
                    player->doorTimer += 10;
                } else if (DUNGEON_KEY_COUNT(gSaveContext.mapIndex) <= 0) {
                    player->doorType = PLAYER_DOORTYPE_TALKING;
                    this->slidingDoor.dyna.actor.textId = 0x1802;
                } else {
                    player->doorTimer += 10;
                }
            }
            ref_func_80122F28(player);
        }
    }
}
