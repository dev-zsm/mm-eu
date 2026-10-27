// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 Player_GetExchangeItemAction(u8 *this) { u8 *p; p = *(u8 **)(this + 0x1CCC); return *(s8 *)(p + 0xA87); }
