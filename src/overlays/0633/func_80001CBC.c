#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6000278;
extern M2C_UNK D_80BF7250;

void func_80001CBC(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_6000278, 0x40000000, 0.0f, 0.0f, 0, -4.0f);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10);
    M2C_FIELD(arg0, u8 *, 0x281) = (u8) (M2C_FIELD(arg0, u8 *, 0x281) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80BF7250;
    M2C_FIELD(arg0, f32 *, 0x70) = 12.0f;
}
