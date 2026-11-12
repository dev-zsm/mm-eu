#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60053D0;
extern M2C_UNK D_80975D80;

void func_80000CB8(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60053D0, 0x3F000000, 0.0f, 7.0f, 3, 0.0f);
    M2C_FIELD(arg0, s16 *, 0x2A0) = 5;
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80975D80;
}
