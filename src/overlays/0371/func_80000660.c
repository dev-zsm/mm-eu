// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_trt.h"

void func_80000660(PlayState* play, EnTrt* this) {
    s8 stickX = CONTROLLER1(&play->state)->rel.stick_x;
    s8 stickY = CONTROLLER1(&play->state)->rel.stick_y;

    if (this->stickAccumX == 0) {
        if ((stickX > 30) || (stickX < -30)) {
            this->stickAccumX = stickX;
        }
    } else if ((stickX <= 30) && (stickX >= -30)) {
        this->stickAccumX = 0;
    } else if ((this->stickAccumX * stickX) < 0) {
        this->stickAccumX = stickX;
    } else {
        this->stickAccumX += stickX;
        if (this->stickAccumX > 2000) {
            this->stickAccumX = 2000;
        } else if (this->stickAccumX < -2000) {
            this->stickAccumX = -2000;
        }
    }
    if (this->stickAccumY == 0) {
        if ((stickY > 30) || (stickY < -30)) {
            this->stickAccumY = stickY;
        }
    } else if ((stickY <= 30) && (stickY >= -30)) {
        this->stickAccumY = 0;
    } else if ((this->stickAccumY * stickY) < 0) {
        this->stickAccumY = stickY;
    } else {
        this->stickAccumY += stickY;
        if (this->stickAccumY > 2000) {
            this->stickAccumY = 2000;
        } else if (this->stickAccumY < -2000) {
            this->stickAccumY = -2000;
        }
    }
}
