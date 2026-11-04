// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightSwitch_Disabled(ObjLightswitch* this, PlayState* play) {
    this->colorShiftTimer--;
    Math_StepToS(&this->edgeRotSpeed, 0, 0xA);
    this->edgeRot += this->edgeRotSpeed;
    this->colorR = (this->colorShiftTimer * (5 << 6)) + (155 << 6);
    this->colorG = (this->colorShiftTimer * ((6 << 6) + 32)) + (125 << 6);

    if (this->colorShiftTimer <= 0) {
        ObjLightswitch_SetupIdle(this);
    } else if (this->colorShiftTimer == 15) {
        this->faceState = LIGHTSWITCH_FACE_ASLEEP;
        Actor_PlaySfx(&this->actor, NA_SE_EV_FOOT_SWITCH);
    }
}
