// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_801A9868(M2C_UNK);                     /* extern */
extern M2C_UNK D_600A954;
extern M2C_UNK D_809CA894;

void func_8000337C(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x328) = &D_809CA894;
    func_80137934(arg0 + 0x148, &D_600A954, 0xC1200000);
    M2C_FIELD(arg0, f32 *, 0x52C) = (f32) func_80134AE8(&D_600A954);
    func_801A9868(0x100100FF);
    M2C_FIELD(arg0, s16 *, 0x24C) = 0;
    M2C_FIELD(arg0, s8 *, 0x242) = 0;
    M2C_FIELD(arg0, s16 *, 0x534) = 0;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
}
