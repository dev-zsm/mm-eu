#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0258.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800BB80C(s32, u8 *);                 /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8098B264(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_8098C8FC;

void func_80001864(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_8098B264(arg0, 6);
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x08000000);
    M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x36C) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 5.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -0.5f;
    if (((M2C_FIELD(arg0, s16 *, 0x2B8) == 0xB) || (M2C_FIELD(arg0, s16 *, 0x2B8) == 0xA)) && (M2C_FIELD(arg0, s16 *, 0x2B6) == 0)) {
        M2C_FIELD(arg0, s16 *, 0x2B8) = 0;
    }
    func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x19);
    func_800BB80C(arg1, arg0);
    func_800B8C4C(arg0, 0x38A3);
    M2C_FIELD(arg0, s16 *, 0x358) = 9;
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8098C8FC;
}
