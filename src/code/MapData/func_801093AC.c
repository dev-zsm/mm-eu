// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 D_801BF8D8[];

void MapData_GetMapTexGameplayDangeonKeepDim(s32 a0, s32 *a1, s32 *a2) {
    u8 *p = D_801BF8D8 + a0 * 10;

    *a1 = p[-0xA00];
    *a2 = p[-0x9FF];
}
