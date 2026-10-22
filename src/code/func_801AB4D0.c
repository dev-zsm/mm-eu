// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void GameOver_Init(void *arg0) {
    M2C_FIELD(arg0, s16 *, 0x17000) = 0;
}
