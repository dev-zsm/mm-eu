// FLAGS: -O2 -g0 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK AudioSeq_SetVolumeScale(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern u16 D_801D3DD0;

void func_801A6AE8(u8 arg0) {
    D_801D3DD0 |= 1 << arg0;
    AudioSeq_SetVolumeScale(0, 2, 0x40, 0xF);
    AudioSeq_SetVolumeScale(3, 2, 0x40, 0xF);
}
