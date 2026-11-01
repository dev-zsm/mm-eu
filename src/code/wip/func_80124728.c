#include "types.h"

s32 Player_SwordFromIA(s32 arg0, s32 arg1) {
    s32 sword = 0;

    if (arg1 == 1) {
        return sword;
    }
    sword = arg1 - 3;
    if ((sword >= 0) && (sword < 4)) {
        return sword;
    }
    return -1;
}
