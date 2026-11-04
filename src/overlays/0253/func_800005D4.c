// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_spiral.h"

void DoorSpiral_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    DoorSpiral* this = (DoorSpiral*)thisx;

    if (this->actor.objectSlot == this->objectSlot) {
        SpiralInfo* spiralInfo = &sSpiralInfoTable[this->unk148];
        Gfx* dList = spiralInfo->dLists[this->direction];

        if (dList != NULL) {
            OPEN_DISPS(play->state.gfxCtx);

            Gfx_SetupDL25_Opa(play->state.gfxCtx);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);

            gSPDisplayList(POLY_OPA_DISP++, spiralInfo->dLists[this->direction]);

            CLOSE_DISPS(play->state.gfxCtx);
        }
    }
}
