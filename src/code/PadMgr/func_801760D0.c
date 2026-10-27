// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern u8 *D_801C9E40;

u8 PadMgr_GetValidControllersMask(void) {
    return *D_801C9E40;
}
