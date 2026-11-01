// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"

s16 AudioScript_ScriptReadS16(u8 **pc) {
    s16 val = *(*pc)++;

    val <<= 8;
    val = *(*pc)++ | val;
    return val;
}
