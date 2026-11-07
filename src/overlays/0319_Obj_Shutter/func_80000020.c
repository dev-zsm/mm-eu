// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_shutter.h"

void ObjShutter_Update(Actor* thisx, PlayState* play2) {
    ObjShutter* this = (ObjShutter*)thisx;
    PlayState* play = play2;
    ScheduleOutput scheduleOutput;

    Schedule_RunScript(play, sScheduleScript, &scheduleOutput);
    if (scheduleOutput.result == 1) {
        if (this->scheduleResult != scheduleOutput.result) {
            this->actor.velocity.y = 0.0f;
        }
        if ((this->verticalOffset >= 80.0f) || (this->scheduleResult == 0)) {
            this->actor.velocity.y = 0.0f;
            this->verticalOffset = 80.0f;
        } else {
            this->verticalOffset += 10.0f;
        }
    } else {
        if (this->scheduleResult != scheduleOutput.result) {
            this->actor.velocity.y = 0.0f;
        }
        if (this->verticalOffset != 0.0f) {
            this->actor.velocity.y -= 3.0f;
            this->verticalOffset += this->actor.velocity.y;
            if (this->verticalOffset <= 0.0f) {
                this->actor.velocity.y = fabsf(this->actor.velocity.y) * 0.8f;
                if ((s32)this->actor.velocity.y == 0) {
                    this->actor.velocity.y = 0.0f;
                    this->verticalOffset = 0.0f;
                }
            }
        }
    }
    this->scheduleResult = scheduleOutput.result;
}
