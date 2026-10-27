// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

extern M2C_UNK D_801E6EF0;

void Sram_IncrementDay(void) {
    if (((s32) M2C_FIELD(&D_801E6EF0, s32 *, 0x18) % 5) < 4) {
        M2C_FIELD(&D_801E6EF0, s32 *, 0x18) = (s32) (M2C_FIELD(&D_801E6EF0, s32 *, 0x18) + 1);
        M2C_FIELD(&D_801E6EF0, s32 *, 0x1C) = (s32) (M2C_FIELD(&D_801E6EF0, s32 *, 0x1C) + 1);
    }
    M2C_FIELD(&D_801E6EF0, s8 *, 0xFE6) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0xFE7) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0xFE8) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0xFE9) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0xFEA) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0xFEB) = 0;
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF41) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF41) & 0xEF);
    M2C_FIELD(&D_801E6EF0, u8 *, 0xF4D) = (u8) (M2C_FIELD(&D_801E6EF0, u8 *, 0xF4D) & 0xFD);
}
