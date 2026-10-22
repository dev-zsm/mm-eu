// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

void SkelAnime_Update(void *arg0) {
    M2C_FIELD(arg0, M2C_UNK (**)(), 0x30)();
}
