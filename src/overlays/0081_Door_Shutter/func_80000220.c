// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void DoorShutter_Init(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    DoorShutter* this = (DoorShutter*)thisx;
    s32 sp24;
    s32 i;

    Actor_ProcessInitChain(&this->slidingDoor.dyna.actor, sInitChain);
    this->doorType = DOORSHUTTER_GET_TYPE(&this->slidingDoor.dyna.actor);
    sp24 = ref_D_808A2240[this->doorType];

    if (sp24 < 0) {
        ShutterSceneInfo* shutterSceneInfo = &ref_D_808A2258[0];

        for (i = 0; i < ARRAY_COUNT(ref_D_808A2258) - 1; i++, shutterSceneInfo++) {
            if (play->sceneId == shutterSceneInfo->sceneId) {
                break;
            }
        }

        sp24 = shutterSceneInfo->index;
        if (sp24 == 6) {
            this->slidingDoor.dyna.actor.flags |= ACTOR_FLAG_UCODE_POINT_LIGHT_ENABLED;
        }
    } else if (sp24 == 0) {
        BossDoorInfo* bossDoorInfo = &ref_D_808A22A0[0];

        for (i = 0; i < ARRAY_COUNT(ref_D_808A22A0) - 1; i++, bossDoorInfo++) {
            if ((play->sceneId == bossDoorInfo->dungeonSceneId) || (play->sceneId == bossDoorInfo->bossSceneId)) {
                break;
            }
        }

        this->slidingDoor.unk_15E = bossDoorInfo->index;
    } else {
        this->slidingDoor.dyna.actor.room = -1;
    }

    if ((this->objectSlot = Object_GetSlot(&play->objectCtx, ref_D_808A2180[sp24].objectId)) <= OBJECT_SLOT_NONE) {
        Actor_Kill(&this->slidingDoor.dyna.actor);
        return;
    }

    DoorShutter_SetupAction(this, DoorShutter_SetupType);
    this->unk_163 = sp24;

    if ((this->doorType == DOORSHUTTER_TYPE_4) || (this->doorType == DOORSHUTTER_TYPE_BOSS_DOOR)) {
        if (!Flags_GetSwitch(play, DOORSHUTTER_GET_SWITCH_FLAG(&this->slidingDoor.dyna.actor))) {
            this->unk_166 = 10;
        }
    }

    Actor_SetFocus(&this->slidingDoor.dyna.actor, 60.0f);
}
