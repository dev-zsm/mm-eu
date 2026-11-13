#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0063.h"

M2C_UNK func_80137788(s32, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_60039C4;
extern M2C_UNK D_8086AFEC;

void func_80001AD4(u8 *arg0) {
    func_80137788(arg0 + 0x144, &D_60039C4, 0x40000000, 0.0f, 0.0f, 0, -2.0f);
    M2C_FIELD(arg0, s16 *, 0x1C) = 7;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086AFEC;
}
