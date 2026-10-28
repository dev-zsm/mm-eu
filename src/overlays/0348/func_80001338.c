// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000174;
extern M2C_UNK D_80A3C248;

void func_80001338(u8 *arg0) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    func_80137934(arg0 + 0x144, &D_6000174, 0xC0A00000, arg0);
    M2C_FIELD(arg0, s16 *, 0x18E) = 3;
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A3C248;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
