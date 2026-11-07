// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_toge.h"

bool ref_func_809A43EC(ObjToge* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    f32 temp_fv1 = player->actor.world.pos.x - this->unk_1B8;
    f32 temp_fa0 = player->actor.world.pos.z - this->unk_1BC;
    f32 temp = -(this->unk_1CC * temp_fa0) + (temp_fv1 * this->unk_1C8);
    f32 temp2 = (this->unk_1CC * temp_fv1) + (temp_fa0 * this->unk_1C8);

    return fabsf(temp) <= this->unk_1C0 && fabsf(temp2) <= this->unk_1C4;
}
