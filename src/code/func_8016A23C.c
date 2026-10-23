#include "types.h"
s32 Player_InCsMode(u8 *);
s32 Play_InCsMode(u8 *a0) {
    return (a0[0x1F2C] != 0) || (Player_InCsMode(a0) != 0);
}
