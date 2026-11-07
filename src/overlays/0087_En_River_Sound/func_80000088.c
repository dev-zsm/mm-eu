// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_river_sound.h"

void EnRiverSound_Update(Actor* thisx, PlayState* play) {
    EnRiverSound* this = (EnRiverSound*)thisx;
    Vec3f* worldPos = &this->actor.world.pos;
    Vec3f eye;
    s32 bgId;

    Math_Vec3f_Copy(&eye, &play->view.eye);

    if (this->actor.params < RS_RIVER_DEFAULT_LOW_FREQ) {
        
        
        Actor_GetClosestPosOnPath(this->pathPoints, this->numPoints, &eye, worldPos, true);
    } else {
        Actor_GetClosestPosOnPath(this->pathPoints, this->numPoints, &eye, worldPos, false);
        if (BgCheck_EntityRaycastFloor5(&play->colCtx, &this->actor.floorPoly, &bgId, &this->actor, worldPos) !=
            BGCHECK_Y_MIN) {
            this->soundFreqIndex = SurfaceType_GetConveyorSpeed(&play->colCtx, this->actor.floorPoly, bgId);
        } else {
            this->soundFreqIndex = 0;
        }

        if (this->soundFreqIndex == 0) {
            this->soundFreqIndex = this->actor.params - RS_RIVER_DEFAULT_LOW_FREQ;
        } else {
            this->soundFreqIndex--;
        }

        this->soundFreqIndex = CLAMP_MAX(this->soundFreqIndex, 2);
    }
}
