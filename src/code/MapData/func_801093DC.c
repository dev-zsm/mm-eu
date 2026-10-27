#include "types.h"
extern u8 D_801BF8D8[];
void MapData_GetMapTexGameplayDangeonKeepOffset(s32 a0, s32 *a1, s32 *a2) {
    u8 *v = (u8 *)D_801BF8D8 + a0 * 10;
    *a1 = *(s16 *)(v - 0x9FE);
    *a2 = *(s16 *)(v - 0x9FC);
}
