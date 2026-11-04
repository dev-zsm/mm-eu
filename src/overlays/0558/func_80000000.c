// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_f40_switch.h"

void BgF40Switch_CheckAll(BgF40Switch* this, PlayState* play) {
    if (play->gameplayFrames != sBgF40SwitchLastUpdateFrame) {
        u32 pressedSwitchFlags[4] = { 0 };
        s32 pad;
        s32 switchFlag;
        s32 isPressed;
        Actor* actor;
        BgF40Switch* actorAsSwitch;
        u32 inCsMode = Player_InCsMode(play);

        for (actor = play->actorCtx.actorLists[ACTORCAT_SWITCH].first; actor != NULL; actor = actor->next) {
            if ((actor->id == ACTOR_BG_F40_SWITCH) && (actor->room == this->dyna.actor.room) &&
                (actor->update != NULL)) {
                actorAsSwitch = (BgF40Switch*)actor;
                actorAsSwitch->wasPressed = actorAsSwitch->isPressed;
                isPressed = DynaPolyActor_IsSwitchPressed(&actorAsSwitch->dyna);
                if (actorAsSwitch->isPressed && (actorAsSwitch->actionFunc == BgF40Switch_IdlePressed)) {
                    
                    
                    if (isPressed || inCsMode) {
                        actorAsSwitch->switchReleaseDelay = 6;
                    } else if (actorAsSwitch->switchReleaseDelay > 0) {
                        actorAsSwitch->switchReleaseDelay--;
                    } else {
                        actorAsSwitch->isPressed = isPressed;
                    }
                } else {
                    
                    actorAsSwitch->isPressed = isPressed;
                }
                if (actorAsSwitch->isPressed) {
                    switchFlag = BGF40SWITCH_GET_SWITCH_FLAG(&actorAsSwitch->dyna.actor);
                    if ((switchFlag > SWITCH_FLAG_NONE) && (switchFlag < 0x80)) {
                        pressedSwitchFlags[(switchFlag & ~0x1F) >> 5] |= 1 << (switchFlag & 0x1F);
                        if (!actorAsSwitch->wasPressed && (actorAsSwitch->actionFunc == BgF40Switch_IdleUnpressed) &&
                            !Flags_GetSwitch(play, switchFlag)) {
                            actorAsSwitch->isInitiator = true;
                        }
                    }
                }
            }
        }
        for (actor = play->actorCtx.actorLists[ACTORCAT_SWITCH].first; actor != NULL; actor = actor->next) {
            if ((actor->id == ACTOR_BG_F40_SWITCH) && (actor->room == this->dyna.actor.room) &&
                (actor->update != NULL)) {
                switchFlag = BGF40SWITCH_GET_SWITCH_FLAG(actor);
                if ((switchFlag > SWITCH_FLAG_NONE) && (switchFlag < 0x80) && Flags_GetSwitch(play, switchFlag) &&
                    !(pressedSwitchFlags[(switchFlag & ~0x1F) >> 5] & (1 << (switchFlag & 0x1F)))) {
                    Flags_UnsetSwitch(play, switchFlag);
                }
            }
        }
        sBgF40SwitchLastUpdateFrame = play->gameplayFrames;
    }
}
