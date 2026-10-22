// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800897D0(M2C_UNK *, M2C_UNK);          /* extern */
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_801E6F14;

void Sram_ResetSave(void) {
    M2C_FIELD(&D_801E6EF0, s32 *, 0) = 0x1C00;
    M2C_FIELD(&D_801E6EF0, s8 *, 4) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 5) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 6) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 7) = 0;
    M2C_FIELD(&D_801E6EF0, s32 *, 0x10) = 0;
    M2C_FIELD(&D_801E6EF0, s32 *, 0x14) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0x21) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0x22) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0x23) = 0;
    func_800897D0(&D_801E6F14, 0xFE8);
}
