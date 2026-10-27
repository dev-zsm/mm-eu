// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef void (*FnP)(s32, u8 *);
void PlayerAnimation_Update(s32 a0, u8 *a1) { ((FnP)*(u32 *)(a1 + 0x30))(a0, a1); }
