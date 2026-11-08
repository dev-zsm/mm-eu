// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 Player_BottleFromIA(struct Player *player, s32 itemAction) {
    s32 temp_v0;

    temp_v0 = itemAction - 0x15;
    if ((temp_v0 >= 0) && (temp_v0 < 0x15)) {
        return temp_v0;
    }
    return -1;
}
