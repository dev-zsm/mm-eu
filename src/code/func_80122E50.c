// FLAGS: -O2 -g3 -mips2
#include "types.h"
s32 Play_SetFog(u8 **, s32);
extern u16 D_801E7F06;

void func_80122E50(u8 **arg0, u8 *arg1) {
    u8 *v1;

    v1 = *arg0;
    if ((D_801E7F06 != 0) || (*(s8 *)(arg1 + 0xD5C) > 0)) {
        *(s32 *)(v1 + 0x2B0) = Play_SetFog(arg0, *(s32 *)(v1 + 0x2B0));
    }
}
