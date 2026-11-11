#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_80136E1C(s32, s32, M2C_UNK *, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK func_80A912D0(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_60013D0;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80A91978;
extern M2C_UNK D_80A92FF0;

void func_8000025C(u8 *arg0, s32 arg1) {
    s32 temp_a1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41C00000);
    temp_a1 = arg0 + 0x144;
    func_80136E1C(arg1, temp_a1, &D_60013D0, 0, 0, 0, 0);
    func_80A912D0(temp_a1, &D_80A92FF0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80A91978;
}
