// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK Audio_SetSequenceMode(M2C_UNK);                     /* extern */
M2C_UNK AudioSfx_PlaySfx(u16, M2C_UNK *, M2C_UNK, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK D_801D3DD4;
extern M2C_UNK D_801D3DE0;
extern M2C_UNK D_801D3DE8;

void Audio_PlaySfx(u16 arg0) {
    AudioSfx_PlaySfx(arg0, &D_801D3DD4, 4, &D_801D3DE0, &D_801D3DE0, &D_801D3DE8);
    if (arg0 == 0x5808) {
        Audio_SetSequenceMode(0);
    }
}
