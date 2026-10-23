#include "types.h"
void CollisionCheck_SetInfo(u8 *a0, void *a1, u8 *a2) {
    a0[0x17] = a2[0];
    *(void **)a0 = a1;
    *(s16 *)(a0 + 0x10) = *(s16 *)(a2 + 2);
    *(s16 *)(a0 + 0x12) = *(s16 *)(a2 + 4);
    a0[0x16] = a2[6];
}
