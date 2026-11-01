// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"


void Play_InitEnvironment(void *arg0, s16 arg1) {
    Skybox_Init(arg0, (u8 *)arg0 + 0x46E0, arg1);
    Environment_Init(arg0, (u8 *)arg0 + 0x17004, 0);
}
