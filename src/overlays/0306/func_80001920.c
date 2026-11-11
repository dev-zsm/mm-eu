#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0306.h"

M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_6000440;
extern M2C_UNK D_80A0DBC8;

void func_80001920(u8 *arg0) {
    func_80137828(arg0 + 0x144, &D_6000440, 0xC0000000, arg0);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
    M2C_FIELD(arg0, M2C_UNK **, 0x298) = &D_80A0DBC8;
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
}
