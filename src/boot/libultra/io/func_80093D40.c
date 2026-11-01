// FLAGS: -O2 -g0 -mips2
#include "sdk/os_vi.h"
#include "sdk/os_sp.h"

u32 osAiGetLength(void) {
    return IO_READ(AI_LEN_REG);
}
