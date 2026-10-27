// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void RcpUtils_PrintRegisterStatus(void);
extern void osDpSetStatus(s32);
extern void __osSpSetStatus(s32);
void func_800849C8(void) { RcpUtils_PrintRegisterStatus(); osDpSetStatus(0x28); __osSpSetStatus(0x4082); RcpUtils_PrintRegisterStatus(); }
