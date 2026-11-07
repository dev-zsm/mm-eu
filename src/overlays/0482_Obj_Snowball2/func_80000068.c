// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball2.h"

void ref_func_80B38E88(ObjSnowball2* this, PlayState* play) {
    s32 temp_v0;

    if (this->unk_1AE == 0) {
        temp_v0 = ref_func_800A8150(ENOBJSNOWBALL2_GET_3F(&this->actor));
        if (temp_v0 >= 0) {
            Item_DropCollectible(play, &this->actor.world.pos, (ENOBJSNOWBALL2_GET_7F00(&this->actor) << 8) | temp_v0);
            this->unk_1AE = 1;
        }
    }
}
