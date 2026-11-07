// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_usiyane.h"

void ref_func_80C081C8(ObjUsiyane* this, PlayState* play) {
    s32 i;
    s32 j;

    this->unk_744 |= 1;

    if (this->unk_740 <= 70) {
        for (i = 0; i < ARRAY_COUNT(this->unk_168[0]); i++) {
            for (j = 0; j < ARRAY_COUNT(this->unk_168); j++) {
                this->unk_168[j][i].unk_0C.y += -0.8f;

                this->unk_168[j][i].unk_00.x += this->unk_168[j][i].unk_0C.x;
                this->unk_168[j][i].unk_00.y += this->unk_168[j][i].unk_0C.y;
                this->unk_168[j][i].unk_00.z += this->unk_168[j][i].unk_0C.z;

                this->unk_168[j][i].unk_18.x += this->unk_168[j][i].unk_1E.x;
                this->unk_168[j][i].unk_18.y += this->unk_168[j][i].unk_1E.y;
                this->unk_168[j][i].unk_18.z += this->unk_168[j][i].unk_1E.z;
            }
        }

    } else if (this->unk_740 >= 70) {
        Actor_Kill(&this->dyna.actor);
    }
    this->unk_740++;
}
