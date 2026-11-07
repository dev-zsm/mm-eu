// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dowsing.h"

s32 ObjDowsing_GetFlag(ObjDowsing* this, PlayState* play) {
    s32 type = DOWSING_GET_TYPE(&this->actor);
    s32 flag = DOWSING_GET_FLAG(&this->actor);

    if (type == DOWSING_COLLECTIBLE) {
        return Flags_GetCollectible(play, flag);
    } else if (type == DOWSING_CHEST) {
        return Flags_GetTreasure(play, flag);
    } else if (type == DOWSING_SWITCH) {
        return Flags_GetSwitch(play, flag);
    } else {
        return 0;
    }
}
