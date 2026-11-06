// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_door_etc.h"

void ref_func_80AC21A0(EnDoorEtc* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    Vec3f playerOffsetFromDoor;
    s32 pad;
    s16 yawDiff;
    s32 yawDiffAbs;

    Actor_WorldToActorCoords(&this->knobDoor.dyna.actor, &playerOffsetFromDoor, &player->actor.world.pos);
    if (!this->knobDoor.requestOpen) {
        if ((!Player_InCsMode(play)) &&
            ((fabsf(playerOffsetFromDoor.y) < 20.0f) && fabsf(playerOffsetFromDoor.x) < 20.0f) &&
            (fabsf(playerOffsetFromDoor.z) < 50.0f)) {
            yawDiff = player->actor.shape.rot.y - this->knobDoor.dyna.actor.shape.rot.y;
            if (playerOffsetFromDoor.z > 0.0f) {
                yawDiff = 0x8000 - yawDiff;
            }
            yawDiffAbs = ABS_ALT(yawDiff);
            if (yawDiffAbs < 0x3000) {
                player->doorDirection = (playerOffsetFromDoor.z >= 0.0f) ? 1.0f : -1.0f;
                player->doorActor = &this->knobDoor.dyna.actor;
                player->doorType = PLAYER_DOORTYPE_TALKING;
            }
        }
    }
    if ((this->knobDoor.dyna.actor.textId == 0x239B) &&
        Flags_GetSwitch(play, ENDOORETC_GET_SWITCH_FLAG(&this->knobDoor.dyna.actor))) {
        Flags_UnsetSwitch(play, ENDOORETC_GET_SWITCH_FLAG(&this->knobDoor.dyna.actor));
        this->actionFunc = ref_func_80AC2154;
        this->knobDoor.dyna.actor.textId = 0x1800; 
        this->unk_1F4 |= 1;
        this->timer = 0x5A;
    }
}
