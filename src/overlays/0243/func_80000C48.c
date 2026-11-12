#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0243.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
extern M2C_UNK D_80980578;

void func_80000C48(u8 *arg0) {
    M2C_FIELD(arg0, f32 *, 0x70) = 3.5f;
    M2C_FIELD(arg0, s16 *, 0x18E) = 0x64;
    M2C_FIELD(arg0, s16 *, 0x190) = -0x1000;
    M2C_FIELD(arg0, s16 *, 0x192) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    M2C_FIELD(arg0, f32 *, 0x160) = 2.0f;
    if (M2C_FIELD(arg0, u8 *, 0xB9) == 1) {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x28);
    } else {
        func_800BC8F4(arg0, 0, 0xFF, 0, 0x28);
    }
    func_800B8C4C(arg0, 0x389E);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80980578;
}
