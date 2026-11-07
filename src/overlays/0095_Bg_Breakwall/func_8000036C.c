// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_breakwall.h"

void ref_func_808B76CC(BgBreakwall* this, PlayState* play) {
    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        BgBreakwallStruct* temp_s1 = &ref_D_808B8140[BGBREAKWALL_GET_F(&this->dyna.actor)];

        this->dyna.actor.objectSlot = this->objectSlot;
        this->dyna.actor.draw = BgBreakwall_Draw;

        if (((BGBREAKWALL_GET_F(&this->dyna.actor)) != BGBREAKWALL_F_7) &&
            ((BGBREAKWALL_GET_F(&this->dyna.actor)) != BGBREAKWALL_F_9) &&
            ((BGBREAKWALL_GET_F(&this->dyna.actor)) != BGBREAKWALL_F_11)) {
            this->dyna.actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        }

        Actor_SetObjectDependency(play, &this->dyna.actor);

        if (temp_s1->unk_0C != NULL) {
            temp_s1->unk_0C = Lib_SegmentedToVirtual(temp_s1->unk_0C);
        }

        if (temp_s1->unk_10 != NULL) {
            DynaPolyActor_Init(&this->dyna, 0);
            DynaPolyActor_LoadMesh(play, &this->dyna, temp_s1->unk_10);
        }

        BgBreakwall_SetupAction(this, temp_s1->unk_18);
        this->dyna.actor.destroy = BgBreakwall_Destroy;
    }
}
