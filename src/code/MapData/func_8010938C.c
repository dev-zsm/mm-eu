// FLAGS: -O1 -g3 -mips2
#include "types.h"
#include "code_funcs.h"
extern u8 D_801BF89C[];
s32 MapData_GetMapTexGameplayDangeonKeep(s32 a0) { return *(s32 *)(D_801BF89C + a0 * 12); }
