// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapDisp_ConvertBossSceneToDungeonScene(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 0x1F:
        return 0x1B;
    case 0x44:
        return 0x21;
    case 0x5F:
        return 0x49;
    case 0x36:
        return 0x16;
    default:
        return arg0;
    }
}
