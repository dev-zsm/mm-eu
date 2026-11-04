// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_demo.h"

void ObjDemo_Update(Actor* thisx, PlayState* play) {
    ObjDemo* this = (ObjDemo*)thisx;

    if ((OBJDEMO_GET_SWITCH_FLAG(&this->actor) != 0xFF) &&
        Flags_GetSwitch(play, OBJDEMO_GET_SWITCH_FLAG(&this->actor))) {
        Actor_Kill(&this->actor);
        return;
    }
    this->actionFunc(this, play);
}
