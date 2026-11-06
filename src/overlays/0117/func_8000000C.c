// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_ana.h"

void DoorAna_Init(Actor* thisx, PlayState* play) {
    DoorAna* this = (DoorAna*)thisx;
    s32 grottoType = DOORANA_GET_TYPE(&this->actor);

    this->actor.shape.rot.y = this->actor.shape.rot.z = 0;

    if (grottoType == DOORANA_TYPE_HIDDEN_STORMS || grottoType == DOORANA_TYPE_HIDDEN_BOMB) {
        if (grottoType == DOORANA_TYPE_HIDDEN_BOMB) {
            Collider_InitAndSetCylinder(play, &this->bombCollider, &this->actor, &sCylinderInit);
        } else {
            this->actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED; 
        }

        Actor_SetScale(&this->actor, 0);
        DoorAna_SetupAction(this, DoorAna_WaitClosed);

    } else {
        DoorAna_SetupAction(this, DoorAna_WaitOpen);
    }

    this->actor.attentionRangeType = ATTENTION_RANGE_0;
}
