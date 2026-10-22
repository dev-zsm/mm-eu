// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 D_801F366C;

s32 SysFlashrom_IsInit(void) {
    return D_801F366C;
}
