// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_y2shutter.h"

void ObjY2shutter_Draw(Actor* thisx, PlayState* play) {
    ObjY2shutter* this = (ObjY2shutter*)thisx;
    ShutterInfo* info = &sShutterInfo[(OBJY2SHUTTER_GET_TYPE(&this->dyna.actor))];

    Gfx_DrawDListOpa(play, info->dList);
}
