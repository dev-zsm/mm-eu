// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_dm_tsg.h"

void DmTsg_Init(Actor* thisx, PlayState* play) {
    DmTsg* this = (DmTsg*)thisx;
    s32 i;

    if (gSaveContext.save.entrance == ENTRANCE(OPENING_DUNGEON, 0)) {
        Actor_SetScale(&this->actor, 0.1f);
        for (i = 0; i < DMTSG_UNK_SIZE; i++) {
            this->unk_78C[i] = Rand_ZeroOne() * 0xFFFF;
            this->unk_856[i] = TRUNCF_BINANG(Rand_ZeroOne() * 200.0f) + 100;
        }
    } else {
        Actor_Kill(&this->actor);
    }
}
