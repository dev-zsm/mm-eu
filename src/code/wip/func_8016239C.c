#include "types.h"

void func_801622F0();

// Not matchable as a standalone function: the ROM's jump table (jtbl_801D7190) targets code that
// lives in separate asm functions (func_801623D0 ...), so only the default path can be written.
void *func_8016239C(u8 arg0) {
    return func_801622F0;
}
