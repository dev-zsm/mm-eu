// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_elevator.h"

void BgDblueElevator_WaitActivation(BgDblueElevator* this, PlayState* play) {
    s32 waterFlow;
    s32 index = BG_DBLUE_ELEVATOR_GET_INDEX(&this->dyna.actor);

    waterFlow = ref_D_80B92960[index].getWaterFlow(this, play);
    if ((waterFlow == BG_DBLUE_ELEVATOR_WATER_FLOW_STOPPED) ||
        (waterFlow == BG_DBLUE_ELEVATOR_WATER_FLOW_BOTH_DIRECTIONS)) {
        this->activationTimer = 60;
    } else {
        this->activationTimer--;
        if (this->activationTimer <= 0) {
            BgDblueElevator_SetupMove(this);
        }
    }
}
