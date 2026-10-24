// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

void func_80189054(Gfx *cmd, u32 hi, u32 lo) {
    cmd->w0 = 0x16000000;
    cmd->w1 = ((hi & 0xFFFF) << 16) | (lo & 0xFFFF);
}
