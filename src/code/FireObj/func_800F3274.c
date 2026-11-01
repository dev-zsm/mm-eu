// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "code_funcs.h"


void FireObj_DestroyLight(u8 *a0, s32 *a1) {
    s32 *a3 = a1;

    LightContext_RemoveLight(a0, a0 + 0x818, *a3);
}
