// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_warp_uzu.h"

void ref_func_80A66384(EnWarpUzu* this, PlayState* play) {
    play->nextEntrance = ENTRANCE(PIRATES_FORTRESS, 10);
    gSaveContext.respawn[RESPAWN_MODE_DOWN].entrance = play->nextEntrance;
    ref_func_80169EFC(play);
    gSaveContext.respawnFlag = -2;
    this->actionFunc = EnWarpUzu_DoNothing;
}
