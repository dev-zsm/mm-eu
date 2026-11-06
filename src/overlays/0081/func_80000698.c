// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void ref_func_808A0F88(DoorShutter* this, PlayState* play) {
    if (Flags_GetClear(play, this->slidingDoor.dyna.actor.room) ||
        Flags_GetClearTemp(play, this->slidingDoor.dyna.actor.room)) {
        this->csId = this->slidingDoor.dyna.actor.csId;
        if (this->doorType == DOORSHUTTER_TYPE_7) {
            if (this->csId != CS_ID_NONE) {
                this->csId = CutsceneManager_GetAdditionalCsId(this->csId);
            }
        }

        if (CutsceneManager_IsNext(this->csId)) {
            CutsceneManager_StartWithPlayerCs(this->csId, &this->slidingDoor.dyna.actor);
            Flags_SetClear(play, this->slidingDoor.dyna.actor.room);
            DoorShutter_SetupAction(this, ref_func_808A1784);
            this->unk_167 = -1;
        } else {
            CutsceneManager_Queue(this->csId);
        }
    } else if (ref_func_808A0E28(this, play) != 0) {
        Player* player = GET_PLAYER(play);

        player->doorType = PLAYER_DOORTYPE_TALKING;
        player->doorActor = &this->slidingDoor.dyna.actor;
        this->slidingDoor.dyna.actor.textId = 0x1801;
        ref_func_80122F28(player);
    }
}
