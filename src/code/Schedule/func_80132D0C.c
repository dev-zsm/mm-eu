#include "types.h"

extern u8 D_801C2D65;
extern u8 D_801C2D67;
extern u8 D_801E6F60[];

s32 Player_GetMask(void *a0);

s32 Schedule_CheckMiscS(void *play, u8 **script, s32 unused) {
    u8 *cmd = *script;

    if (((cmd[1] == 0) && (D_801E6F60[D_801C2D65] == 0x2D)) ||
        ((cmd[1] == 1) && (D_801E6F60[D_801C2D67] == 0x2F)) ||
        ((cmd[1] == 2) && (Player_GetMask(play) == 7))) {
        *script += ((s8 *)cmd)[2];
    }
    return 0;
}
