// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/overlays/0056.h"

s32 func_80838168(s32, s32);
s32 func_808388B0(s32, s32);
s32 func_8083C914(s32, s32);

s32 func_800123EC(s32 arg0, s32 arg1) {
    return func_80838168(arg0, arg1) != 0 || func_808388B0(arg0, arg1) != 0 || func_8083C914(arg0, arg1) != 0;
}
