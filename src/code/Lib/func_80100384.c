// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

u32 Lib_VirtualToPhysical(void *ptr) {
    if (ptr == 0) {
        return 0;
    }
    return (u8 *)ptr + 0x80000000;
}
