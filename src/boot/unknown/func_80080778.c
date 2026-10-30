// FLAGS: -O1 -g3 -mips2
#include "os_internal.h"

/* Applies the D_80096CC4 flag to osViBlack; when D_80096D00 is 2, also resets the y scale. */
void func_80080778(void) {
    // matching: the flags are read through non-volatile casts
    if (*(u8 *)&D_80096CC4 != 0) {
        osViBlack(1);
    } else {
        osViBlack(0);
    }
    if (*(s32 *)&D_80096D00 == 2) {
        osViSetYScale(1.0f);
    }
}
