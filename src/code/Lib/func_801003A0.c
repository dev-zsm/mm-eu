// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 Lib_PhysicalToVirtual(s32 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return arg0 + 0x80000000;
}
