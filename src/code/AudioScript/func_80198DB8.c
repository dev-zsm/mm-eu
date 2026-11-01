// FLAGS: -O2 -g0 -mips2
#include "types.h"
#include "code_funcs.h"
u8 AudioScript_ScriptReadU8(u8 **a0) { return *(*a0)++; }
