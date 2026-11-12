#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137934(u8 *, M2C_UNK *, f32, u8 *); /* extern */
extern M2C_UNK D_6023DAC;
extern M2C_UNK D_809DABB8;

void func_80001494(u8 *arg0, M2C_UNK arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809DABB8;
    func_80137934(arg0 + 0x190, &D_6023DAC, 0.0f, arg0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    M2C_FIELD(arg0, s16 *, 0x17D8) = 0x7F00;
    M2C_FIELD(arg0, s16 *, 0x15C) = 0x14;
    M2C_FIELD(arg0, f32 *, 0x17E8) = 5120.0f;
}
