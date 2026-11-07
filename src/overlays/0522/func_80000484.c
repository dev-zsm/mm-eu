// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_dblue_elevator.h"

void BgDblueElevator_Init(Actor* thisx, PlayState* play2) {
    BgDblueElevator* this = (BgDblueElevator*)thisx;
    PlayState* play = play2;
    s32 index = BG_DBLUE_ELEVATOR_GET_INDEX(&this->dyna.actor);
    BgDblueElevatorStruct1* ptr = &ref_D_80B92960[index];
    s32 waterFlow;

    Actor_ProcessInitChain(&this->dyna.actor, sInitChain);
    DynaPolyActor_Init(&this->dyna, DYNA_TRANSFORM_POS);
    DynaPolyActor_LoadMesh(play, &this->dyna, &gGreatBayTempleObjectElevatorCol);
    waterFlow = ptr->getWaterFlow(this, play);

    if (waterFlow == BG_DBLUE_ELEVATOR_WATER_FLOW_REVERSED) {
        this->direction = -ptr->initialDirection;
    } else {
        this->direction = ptr->initialDirection;
    }

    BgDblueElevator_CheckWaterBoxInfo(this, play);

    if ((waterFlow == BG_DBLUE_ELEVATOR_WATER_FLOW_STOPPED) ||
        (waterFlow == BG_DBLUE_ELEVATOR_WATER_FLOW_BOTH_DIRECTIONS)) {
        BgDblueElevator_SetupWaitActivation(this);
    } else {
        BgDblueElevator_SetupMove(this);
    }
}
