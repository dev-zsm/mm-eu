// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void * Lib_PhysicalToVirtual(u32 ptr) {
    if (ptr == 0) {
        return 0;
    }
    return ptr + 0x80000000;
}
