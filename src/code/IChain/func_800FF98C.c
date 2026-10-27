#include "types.h"
void func_800FF98C(u8 *a0, u16 *a1) { s16 *p = (s16 *)a1; *(s16 *)(a0 + (a1[0] & 0x7FF)) = p[1]; }
