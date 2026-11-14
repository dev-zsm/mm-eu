// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ObjToudai_Update), score 1.00 (1 differ, size +1)
#include "generated/mm/z_obj_toudai.h"

void func_8000097C(Actor* thisx, PlayState* play) {
    ObjToudai* this = (ObjToudai*)thisx;
    u8 temp_v0 = ref_func_80A342F4(this->unk_238);

    if (temp_v0 != this->unk_236) {
        this->unk_236 = temp_v0;
        this->unk_238 = Rand_S16Offset(0, 50);
    }

    Math_ApproachF(&this->unk_228, (this->unk_236 == 0) ? 0.0f : 1.0f, 0.01f, 1000.0f);
    this->unk_234 += 100;
    thisx->shape.rot.y = TRUNCF_BINANG(Math_SinS(this->unk_234) * 16000.0f) + thisx->world.rot.y;
}
