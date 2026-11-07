// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_RotateOnMinuteChange(ObjTokeidai* this, s32 playSfx) {
    s32 currentClockMinute = GET_CURRENT_CLOCK_MINUTE(this);

    if (currentClockMinute != this->clockMinute) {
        if ((this->minuteRingOrExteriorGearRotationTimer == 8) && playSfx) {
            Actor_PlaySfx(&this->actor, NA_SE_EV_CLOCK_TOWER_SECOND_HAND);
        }

        if (this->minuteRingOrExteriorGearRotationTimer > 8) {
            
            
            this->minuteRingOrExteriorGearAngularVelocity += 0x3C;
            this->minuteRingOrExteriorGearRotation += this->minuteRingOrExteriorGearAngularVelocity;
        } else {
            
            
            if ((this->minuteRingOrExteriorGearRotationTimer & 3) == 0) {
                this->minuteRingOrExteriorGearRotation += 0x5A;
            }
            if ((this->minuteRingOrExteriorGearRotationTimer & 3) == 1) {
                this->minuteRingOrExteriorGearRotation -= 0x5A;
            }
        }

        this->minuteRingOrExteriorGearRotationTimer++;

        if (((currentClockMinute == 15) && (this->minuteRingOrExteriorGearRotation < 0)) ||
            ((currentClockMinute != 15) &&
             this->minuteRingOrExteriorGearRotation > GET_MINUTE_RING_OR_EXTERIOR_GEAR_ROTATION(currentClockMinute))) {
            this->minuteRingOrExteriorGearRotation = GET_MINUTE_RING_OR_EXTERIOR_GEAR_ROTATION(currentClockMinute);
            this->clockMinute = currentClockMinute;
            this->minuteRingOrExteriorGearAngularVelocity = 0x5A;
            this->minuteRingOrExteriorGearRotationTimer = 0;
        }
    }
}
