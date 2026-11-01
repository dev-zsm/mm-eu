#include "types.h"
#include "generated/code_funcs.h"
s32 Play_InCsMode(u8 *a0) {
    return (a0[0x1F2C] != 0) || (Player_InCsMode(a0) != 0);
}
