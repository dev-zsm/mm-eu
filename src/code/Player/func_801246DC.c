// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 Player_ExplosiveFromIA(struct Player *player, s32 itemAction) {
    s32 temp_v0;

    temp_v0 = itemAction - 0xE;
    if ((temp_v0 >= 0) && (temp_v0 < 3)) {
        return temp_v0;
    }
    return -1;
}
