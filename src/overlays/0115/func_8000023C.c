// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_object_kankyo.h"

void ObjectKankyo_Init(Actor* thisx, PlayState* play) {
    ObjectKankyo* this = (ObjectKankyo*)thisx;
    s16 i;

    for (i = 0; i < ARRAY_COUNT(this->unk_14C); i++) {
        this->unk_14C[i].unk_1C = 0;
    }

    this->actor.room = -1;
    switch (this->actor.params) {
        case 0:
            ref_func_808DBE8C(this);
            break;

        case 2:
            play->envCtx.precipitation[PRECIP_SNOW_CUR] = 128;
            ref_func_808DBFB0(this, play);
            break;

        case 1:
        case 3:
            ref_func_808DBEB0(this, play);
            break;

        case 4:
            ref_func_808DC038(this, play);
            break;
    }
}
