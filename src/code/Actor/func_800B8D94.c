#include "types.h"
void Actor_PlaySfx_Flagged(u8 *a0, u16 a1) {
    *(u16 *)(a0 + 0x50) = a1;
    a0[0x39] = a0[0x39] & 0xFFE0;
    a0[0x39] = a0[0x39] | 1;
}
