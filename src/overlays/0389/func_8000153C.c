// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_RotateOnHourChange(ObjTokeidai* this, PlayState* play) {
    s32 currentClockHour = GET_CURRENT_CLOCK_HOUR(this);

    if (currentClockHour != this->clockHour) {
        if (this->clockFaceRotationTimer > 12) {
            
            
            this->clockFaceAngularVelocity += 0xA;
            this->clockFaceRotation += this->clockFaceAngularVelocity;
        } else {
            
            
            if ((this->clockFaceRotationTimer & 3) == 0) {
                this->clockFaceRotation += 0x3C;
            }
            if ((this->clockFaceRotationTimer & 3) == 1) {
                this->clockFaceRotation -= 0x3C;
            }
        }

        this->clockFaceRotationTimer++;

        if (((currentClockHour == 12) && (this->clockFaceRotation < 0)) ||
            ((currentClockHour != 12) && (this->clockFaceRotation > GET_CLOCK_FACE_ROTATION(currentClockHour)))) {
            this->clockFaceRotation = GET_CLOCK_FACE_ROTATION(currentClockHour);
            this->clockHour = currentClockHour;
            this->clockFaceAngularVelocity = 0;
            this->clockFaceRotationTimer = 0;
        }
    }

    
    
    if (this->sunMoonPanelRotation != ObjTokeidai_GetTargetSunMoonPanelRotation()) {
        if (this->clockHour == 6) {
            this->sunMoonPanelAngularVelocity += 0x222;
            this->sunMoonPanelRotation += this->sunMoonPanelAngularVelocity;
            if (this->sunMoonPanelRotation > 0x10000) {
                this->sunMoonPanelRotation = ObjTokeidai_GetTargetSunMoonPanelRotation();
                this->sunMoonPanelAngularVelocity = 0;
            }
        }
        if (this->clockHour == 18) {
            this->sunMoonPanelAngularVelocity += 0x222;
            this->sunMoonPanelRotation += this->sunMoonPanelAngularVelocity;
            if (this->sunMoonPanelRotation > 0x8000) {
                this->sunMoonPanelRotation = ObjTokeidai_GetTargetSunMoonPanelRotation();
                this->sunMoonPanelAngularVelocity = 0;
            }
        }
    }
}
