// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000A54;
extern M2C_UNK D_80B00358;

void func_80001204(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_6000A54, 0xC0400000, arg0);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) (M2C_FIELD(arg0, s16 *, 0xBE) + 0x8000);
    M2C_FIELD(arg0, s16 *, 0x192) = 5;
    M2C_FIELD(arg0, u8 *, 0x191) = (u8) (M2C_FIELD(arg0, u8 *, 0x191) | 0xB);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80B00358;
    M2C_FIELD(arg0, f32 *, 0x70) = 5.0f;
}
