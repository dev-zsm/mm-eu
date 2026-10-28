// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

s16 func_800FF860(u8 *, u8 *);                  /* extern */
M2C_UNK func_80A61610(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80A61988(u8 *);                      /* extern */
extern M2C_UNK D_80A62400;

void func_80000D80(u8 *arg0) {
    func_80A61610(arg0, 0xB);
    M2C_FIELD(arg0, s32 *, 0x37C) = 0;
    func_80A61988(arg0);
    M2C_FIELD(arg0, s16 *, 0x32) = func_800FF860(arg0 + 0x24, arg0 + 0x408);
    M2C_FIELD(arg0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0x32) + 0x8000);
    M2C_FIELD(arg0, s16 *, 0x2B2) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_80A62400;
}
