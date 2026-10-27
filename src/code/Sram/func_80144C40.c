// FLAGS: -O2 -g3 -mips2
// STATUS: verified draft (raw field offsets from the automatic draft; to be cleaned up)
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEA90(M2C_UNK *, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK Sram_ResetSave();                            /* extern */
M2C_UNK Sram_GenerateRandomSaveFields();                            /* extern */
extern M2C_UNK D_801C7D58;
extern M2C_UNK D_801C7D80;
extern M2C_UNK D_801C7DA4;
extern M2C_UNK D_801C7E2C;
extern M2C_UNK D_801E6EF0;
extern M2C_UNK D_801E6F14;
extern M2C_UNK D_801E6F3C;
extern M2C_UNK D_801E6F60;
extern M2C_UNK D_801E7EFA;

void Sram_InitNewSave(void) {
    M2C_FIELD(&D_801E6EF0, s8 *, 0x20) = 4;
    M2C_FIELD(&D_801E6EF0, s32 *, 0x1C) = 0;
    M2C_FIELD(&D_801E6EF0, s32 *, 0x18) = 0;
    M2C_FIELD(&D_801E6EF0, s16 *, 0xC) = 0x3FFF;
    Sram_ResetSave();
    func_800FEA90(&D_801E6F14, &D_801C7D58, 0x28);
    func_800FEA90(&D_801E6F3C, &D_801C7D80, 0x22);
    func_800FEA90(&D_801E6F60, &D_801C7DA4, 0x88);
    func_800FEA90(&D_801E7EFA, &D_801C7E2C, 2);
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1000) = 0x35;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1002) = -0x58C;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1004) = 0x101;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1006) = -0x505;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x1008) = -0x7554;
    M2C_FIELD(&D_801E6EF0, s16 *, 0x3F4A) = 0;
    M2C_FIELD(&D_801E6EF0, s8 *, 0x38) = 0;
    Sram_GenerateRandomSaveFields();
}
