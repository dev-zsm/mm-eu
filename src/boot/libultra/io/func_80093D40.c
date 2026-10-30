// FLAGS: -O2 -g0 -mips2
#include "os_vi.h"
#include "os_sp.h"

u32 osAiGetLength(void) {
    return IO_READ(AI_LEN_REG);
}
