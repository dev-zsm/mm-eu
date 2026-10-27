#include "types.h"
void IChain_Apply_s32(u8 *a0, u16 *a1) { s16 *p = (s16 *)a1; *(s32 *)(a0 + (a1[0] & 0x7FF)) = p[1]; }
