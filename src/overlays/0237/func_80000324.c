// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure3.h"

void ref_func_8098F364(ObjMure3* this, PlayState* play) {
    s16 count = sRupeeCounts[OBJMURE3_PARAM_RUPEEINDEX(&this->actor)];
    s32 i;
    EnItem00** collectible;

    for (i = 0; i < count; i++) {
        collectible = &this->unk148[i];
        if ((!((this->unk164 >> i) & 1)) && (*collectible != NULL)) {
            if (((*collectible)->unk1A4 != 0) || ((*collectible)->actor.update == NULL)) {
                this->unk164 |= (1 << i);
            } else {
                Actor_Kill(&(*collectible)->actor);
            }
        }
        *collectible = NULL;
    }
}
