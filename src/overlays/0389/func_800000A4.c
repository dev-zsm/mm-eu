// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_Clock_Init(ObjTokeidai* this) {
    s32 currentClockHour;

    ObjTokeidai_SetupClockOrExteriorGear(this);
    currentClockHour = GET_CURRENT_CLOCK_HOUR(this);
    this->clockHour = currentClockHour;
    this->clockFaceRotation = GET_CLOCK_FACE_ROTATION(currentClockHour);
    this->clockFaceAngularVelocity = 0;
    this->clockFaceRotationTimer = 0;
    this->sunMoonPanelAngularVelocity = 0;
    this->sunMoonPanelRotation = ObjTokeidai_GetTargetSunMoonPanelRotation();
}
