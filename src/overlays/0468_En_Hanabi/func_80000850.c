// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_hanabi.h"

void EnHanabi_Destroy(Actor* thisx, PlayState* play2) {
    PlayState* play = play2;
    EnHanabi* this = (EnHanabi*)thisx;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(this->unk_4634); i++) {
        LightContext_RemoveLight(play, &play->lightCtx, this->unk_4634[i]);
    }
}
