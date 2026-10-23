#include "types.h"
extern u8 D_801BF89C[];
void MapData_GetMapTexOffsetGameplayDangeonKeep(s32 a0, s32 *a1, s32 *a2) {
    u8 *v = D_801BF89C + a0 * 12;
    *a1 = v[6];
    *a2 = v[7];
}
