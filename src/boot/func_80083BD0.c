// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"
extern u8 *D_8009C220;
s32 FaultDrawer_SetDrawerFrameBuffer(s32 a0, u16 a1, u16 a2);
void Fault_SetFrameBuffer(s32 a0, u16 a1, u16 a2) { *(s32 *)(D_8009C220 + 0x844) = a0; FaultDrawer_SetDrawerFrameBuffer(a0, a1, a2); }
