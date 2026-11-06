// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_kusa2.h"

void ref_func_80A5B334(EnKusa2* this, PlayState* play) {
    s32 i;
    EnKusa2** ptr;

    for (i = 0; i < ARRAY_COUNT(this->unk_194); i++) {
        ptr = &this->unk_194[i];

        if (*ptr != NULL) {
            if (!Actor_HasParent(&(*ptr)->actor, play)) {
                Actor_Kill(&(*ptr)->actor);
            }
            *ptr = NULL;
        }
    }
}
