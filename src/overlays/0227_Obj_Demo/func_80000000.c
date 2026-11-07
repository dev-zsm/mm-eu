// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_demo.h"

void ObjDemo_Init(Actor* thisx, PlayState* play) {
    ObjDemo* this = (ObjDemo*)thisx;

    thisx->params = OBJDEMO_GET_SWITCH_FLAG_MASK(thisx);
    if ((OBJDEMO_GET_SWITCH_FLAG(thisx) != 0xFF) && Flags_GetSwitch(play, OBJDEMO_GET_SWITCH_FLAG(thisx))) {
        Actor_Kill(&this->actor);
        return;
    }
    if (thisx->shape.rot.x < 0) {
        this->unk_148 = 1;
        thisx->shape.rot.x = -thisx->shape.rot.x;
    }
    if (thisx->shape.rot.x == 0) {
        this->xzRange = 80.0f;
    } else {
        this->xzRange = thisx->shape.rot.x * 4.0f;
        thisx->shape.rot.x = 0;
        thisx->world.rot.x = 0;
    }
    if (thisx->shape.rot.z == 0) {
        this->yRange = 60.0f;
    } else {
        this->yRange = thisx->shape.rot.z * 4.0f;
        thisx->shape.rot.z = 0;
        thisx->world.rot.z = 0;
    }
    ref_func_80983634(play);
    this->actionFunc = ref_func_80983678;
}
