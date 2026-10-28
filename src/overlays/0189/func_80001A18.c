// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_801667DC(M2C_UNK);                     /* extern */
M2C_UNK func_80954540(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_80955DA4;

void func_80001A18(u8 *arg0) {
    M2C_FIELD(arg0, s16 *, 0x190) = 0;
    M2C_FIELD(arg0, s32 *, 0x1A4) = 0;
    M2C_FIELD(arg0, f32 *, 0x20C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x210) = 60.0f;
    func_80954540(arg0, 4);
    func_800FF30C(arg0 + 0x22C, arg0 + 8);
    func_801667DC(0xB4);
    M2C_FIELD(arg0, M2C_UNK **, 0x148) = &D_80955DA4;
}
