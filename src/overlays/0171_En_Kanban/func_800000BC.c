// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kanban.h"

void EnKanban_Init(Actor* thisx, PlayState* play) {
    EnKanban* this = (EnKanban*)thisx;

    Actor_SetScale(&this->actor, 0.01f);
    if (this->actor.params != ENKANBAN_PIECE) {
        this->actor.attentionRangeType = ATTENTION_RANGE_0;
        this->actor.flags |= ACTOR_FLAG_ATTENTION_ENABLED;
        this->unk_19A = Rand_ZeroFloat(1.9f);
        Collider_InitCylinder(play, &this->collider);
        Collider_SetCylinder(play, &this->collider, &this->actor, &sCylinderInit);

        if (this->actor.params == ENKANBAN_FISHING) {
            if (LINK_IS_CHILD) {
                this->actor.textId = 0x409D;
            } else {
                this->actor.textId = 0x4090;
            }
        } else {
            this->actor.textId = this->actor.params | ENKANBAN_FISHING;
        }

        this->bounceX = 1;
        this->partFlags = 0xFFFF;
        Actor_UpdateBgCheckInfo(play, &this->actor, 10.0f, 10.0f, 50.0f, UPDBGCHECKINFO_FLAG_4);
        ref_func_80954960(this);
    }
}
