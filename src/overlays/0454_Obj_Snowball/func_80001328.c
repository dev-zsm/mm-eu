// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B03FF8(ObjSnowball* this, PlayState* play) {
    s32 pad;
    s16 rotY = this->actor.home.rot.y;
    ObjSnowballStruct2* sp18 = &ref_D_80B04F84[rotY];

    if (sp18->unk_04 != NULL) {
        sp18->unk_04(this, play);
    }

    Actor_PlaySfx(&this->actor, NA_SE_EV_SNOWBALL_BROKEN);

    if (rotY == 5) {
        Flags_SetSwitch(play, OBJSNOWBALL_GET_SWITCH_FLAG(&this->actor));
    }
}
