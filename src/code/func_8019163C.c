// FLAGS: -O2 -g0 -mips2
#include "types.h"
extern s32 AudioLoad_SyncLoad();
void func_8019163C(s32 a0, s32 a1) { s32 sp1C; AudioLoad_SyncLoad(a0, a1, &sp1C); }
