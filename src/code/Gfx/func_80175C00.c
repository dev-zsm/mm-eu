// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

union Gfx * Gfx_Open(union Gfx *gfx) {
    return (u8 *)gfx + 8;
}
