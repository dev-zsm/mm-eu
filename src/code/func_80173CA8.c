#include "types.h"
s32 THA_AllocTailAlign(u8 *a0, s32 a1, s32 a2) { return *(s32 *)(a0 + 0xC) = ((*(s32 *)(a0 + 0xC) & a2) - a1) & a2; }
