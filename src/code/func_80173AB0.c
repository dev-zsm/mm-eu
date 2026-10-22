// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 THA_AllocHead(s32, s32, s32);

void THGA_AllocDisplayList(s32 arg0, s32 arg1) {
    THA_AllocHead(arg0, arg1 * 8, arg1);
}
