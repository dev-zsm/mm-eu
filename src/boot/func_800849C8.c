// FLAGS: -O2 -g3 -mips2
#include "types.h"
extern void func_800849A0(void);
extern void func_80091450(s32);
extern void func_80095420(s32);
void func_800849C8(void) { func_800849A0(); func_80091450(0x28); func_80095420(0x4082); func_800849A0(); }
