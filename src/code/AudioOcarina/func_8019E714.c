// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801D11E8;
extern u8 D_801D145C;
extern M2C_UNK D_801F84B0;

void AudioOcarina_SetCustomSequence(void) {
    if ((D_801D145C != 0) && (((u32) M2C_FIELD(&D_801F84B0, u32 *, 0x45C0) >> 0x1F) != 0) && (M2C_FIELD(&D_801F84B0, u8 *, 0x4718) == 0xFF)) {
        M2C_FIELD(&D_801F84B0, M2C_UNK **, 0x45D8) = &D_801D11E8;
        D_801D145C = 0;
    }
}
