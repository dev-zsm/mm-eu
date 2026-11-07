// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_flowerpot.h"

void ref_func_80A1B914(ObjFlowerpot* this, PlayState* play) {
    if (!(this->unk_1EA & 4)) {
        s32 temp_v0 = ref_func_800A8150(ENOBJFLOWERPOT_GET_3F(&this->actor));

        if (temp_v0 >= 0) {
            s32 params = ENOBJFLOWERPOT_GET_7F00(&this->actor);

            Item_DropCollectible(play, &this->actor.world.pos, temp_v0 | (params << 8));
            this->unk_1EA |= 4;
        }
    }
}
