// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s32 func_80134AE8(M2C_UNK *);                       /* extern */
M2C_UNK func_80137828(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60269EC;
extern M2C_UNK D_809DDBF8;

void func_800044E8(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f6;

    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809DDBF8;
    func_80137828(arg0 + 0x190, &D_60269EC, 0xC0A00000, arg0);
    temp_f6 = (f32) func_80134AE8(&D_60269EC);
    M2C_FIELD(arg0, s16 *, 0x14C) = 0;
    M2C_FIELD(arg0, f32 *, 0x1D4) = temp_f6;
}
