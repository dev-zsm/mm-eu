// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_numa_hana.h"

void BgNumaHana_ClosedIdle(BgNumaHana* this, PlayState* play) {
    if (this->fire.state != FIRE_STATE_NOT_LIT) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_FLAME_IGNITION);
        if (CutsceneManager_IsNext(this->dyna.actor.csId)) {
            CutsceneManager_StartWithPlayerCs(this->dyna.actor.csId, &this->dyna.actor);
            SET_WEEKEVENTREG(WEEKEVENTREG_12_01);
            Flags_SetSwitch(play, BG_NUMA_HANA_SWITCH_FLAG(&this->dyna.actor));
            BgNumaHana_SetupUnfoldInnerPetals(this);
        } else {
            CutsceneManager_Queue(this->dyna.actor.csId);
        }
    }
}
