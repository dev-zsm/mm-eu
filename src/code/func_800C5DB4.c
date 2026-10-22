// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 DynaPoly_IsBgIdBgActor(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 0x32)) {
        return 0;
    }
    return 1;
}
