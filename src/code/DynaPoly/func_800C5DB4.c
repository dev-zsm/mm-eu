// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

s32 DynaPoly_IsBgIdBgActor(s32 bgId) {
    if ((bgId < 0) || (bgId >= 0x32)) {
        return 0;
    }
    return 1;
}
