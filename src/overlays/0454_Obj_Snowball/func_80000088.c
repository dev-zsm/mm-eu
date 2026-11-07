// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B02D58(ObjSnowball* this, PlayState* play) {
    s32 temp_v0 = ref_func_800A8150(OBJSNOWBALL_GET_SWITCH_FLAG(&this->actor));

    if (temp_v0 >= 0) {
        Item_DropCollectible(play, &this->actor.home.pos, (OBJSNOWBALL_GET_7F00(&this->actor) << 8) | temp_v0);
    }
}
