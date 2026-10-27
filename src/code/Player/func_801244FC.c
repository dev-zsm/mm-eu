// FLAGS: -O2 -g3 -mips2
#include "types.h"
void Player_RemoveMask(u8 *this) { u8 *p; p = *(u8 **)(this + 0x1CCC); *(p + 0x153) = 0; }
