// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"
#include "generated/code_funcs.h"

s32 SkelAnime_Update(struct SkelAnime *skelAnime) {
    M2C_FIELD(skelAnime, M2C_UNK (**)(), 0x30)();
}
