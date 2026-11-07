// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_SetupClockOrExteriorGear(ObjTokeidai* this) {
    s32 currentClockMinute = GET_CURRENT_CLOCK_MINUTE(this);

    this->clockMinute = currentClockMinute;
    this->minuteRingOrExteriorGearRotation = GET_MINUTE_RING_OR_EXTERIOR_GEAR_ROTATION(currentClockMinute);
    this->minuteRingOrExteriorGearAngularVelocity = 0x3C;
    this->minuteRingOrExteriorGearRotationTimer = 0;
}
