// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokeidai.h"

void ObjTokeidai_TowerClock_SlideOff(ObjTokeidai* this, PlayState* play) {
    f32 cos;
    f32 sin;
    Actor* thisx = &this->actor;

    if (this->slidingClockFaceAngle < 0x4000) {
        this->slidingClockFaceAngle += 0x28;
    }
    if (this->slidingClockFaceAngle > 0x800) {
        this->aerialClockFaceSpeed += 4;
    }

    if (this->aerialClockFaceSpeed < 0x80) {
        thisx->shape.rot.x = this->slidingClockFaceAngle - 0x4000;
        this->fallingClockFaceAngularVelocity = 0x28;
    } else {
        if (thisx->shape.rot.x < -0x1000) {
            thisx->shape.rot.x += this->fallingClockFaceAngularVelocity;
            if (this->fallingClockFaceAngularVelocity < 0x1E0) {
                this->fallingClockFaceAngularVelocity += 0xA;
            }
        } else {
            thisx->shape.rot.x += this->fallingClockFaceAngularVelocity;
            this->actionFunc = ObjTokeidai_TowerClock_Fall;
            thisx->terminalVelocity = -7.5f;
            thisx->gravity = -0.75f;
            thisx->velocity.y = -2.0f;
        }
    }

    sin = Math_SinS(this->slidingClockFaceAngle);
    cos = Math_CosS(this->slidingClockFaceAngle);
    thisx->world.pos.y = (1178.0f * cos) - (this->aerialClockFaceSpeed * sin) + thisx->home.pos.y;
    thisx->world.pos.z = (1178.0f * sin) + (this->aerialClockFaceSpeed * cos) + thisx->home.pos.z;
}
