// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_osn.h"

void func_80000C98(EnOsn* this, PlayState* play) {
    s16 yaw = this->actor.yawTowardsPlayer - this->actor.shape.rot.y;

    if ((gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] != ITEM_NONE) &&
    !CHECK_QUEST_ITEM(QUEST_SONG_HEALING)) {
        if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
            this->actionFunc = EnOsn_StartCutscene;
        } else if (((this->actor.xzDistToPlayer < 100.0f) || this->actor.isLockedOn) && (yaw < 0x4000) &&
        (yaw > -0x4000)) {
            Actor_OfferTalkNearColChkInfoCylinder(&this->actor, play);
            this->actor.textId = 0xFFFF;
        }
    } else if (Actor_TalkOfferAccepted(&this->actor, &play->state)) {
        this->textId = EnOsn_GetInitialText(this, play);
        Message_StartTextbox(play, this->textId, &this->actor);
        this->actionFunc = EnOsn_Talk;
    } else if (((this->actor.xzDistToPlayer < 100.0f) || this->actor.isLockedOn) && (yaw < 0x4000) && (yaw > -0x4000)) {
        Actor_OfferTalkNearColChkInfoCylinder(&this->actor, play);
    }
}
