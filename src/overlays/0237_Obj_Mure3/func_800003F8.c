// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure3.h"

void ref_func_8098F438(ObjMure3* this, PlayState* play) {
    s16 count = sRupeeCounts[OBJMURE3_PARAM_RUPEEINDEX(&this->actor)];
    s32 i;

    for (i = 0; i < count; i++) {
        EnItem00** collectible = &this->unk148[i];

        if ((*collectible != NULL) && !((this->unk164 >> i) & 1)) {
            if ((*collectible)->unk1A4 != 0) {
                Flags_SetSwitch(play, OBJMURE3_GET_SWITCH_FLAG(&this->actor));
            }
            if ((*collectible)->actor.update == NULL) {
                this->unk164 |= (1 << i);
                this->unk148[i] = NULL;
            }
        }
    }
}
