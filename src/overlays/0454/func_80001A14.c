// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_snowball.h"

void ref_func_80B046E4(ObjSnowball* this, PlayState* play) {
    Vec3f sp44;
    s32 i;

    ref_func_80B03E2C(this, play);

    for (i = 0; i < ARRAY_COUNT(this->unk_1A8); i++) {
        sp44.x = this->unk_1A8[i].unk_00.x;
        sp44.y = this->unk_1A8[i].unk_00.y - (60.0f * this->unk_20C);
        sp44.z = this->unk_1A8[i].unk_00.z;
        ref_func_80B03A80(play, this->unk_20C, &sp44);
    }

    this->actor.draw = ref_func_80B04D34;
    this->actor.floorPoly = NULL;
    this->unk_208 = 50;
    this->actionFunc = ref_func_80B047C0;
}
