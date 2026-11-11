#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0232.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800FFBF8(u8 *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8096DE80(u8 *, M2C_UNK *, M2C_UNK);  /* extern */
M2C_UNK func_8096E6B4(u8 *);                      /* extern */
M2C_UNK func_8096E7DC(u8 *, f32);             /* extern */
extern M2C_UNK D_8096F44C;
extern M2C_UNK D_8097109C;

void func_800014D8(u8 *arg0, M2C_UNK arg1) {
    s16 temp_v0;
    s16 var_v1;

    temp_v0 = M2C_FIELD(arg0, s16 *, 0x282);
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
    if (temp_v0 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x282) = (s16) (temp_v0 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x282);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x282) = 0x32;
        func_8096DE80(arg0 + 0x14C, &D_8097109C, 2);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096F44C;
    } else {
        func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 4, 0x3E8, 1);
        if (M2C_FIELD(arg0, u16 *, 0x90) & 8) {
            M2C_FIELD(arg0, s16 *, 0xBE) = (s16) M2C_FIELD(arg0, s16 *, 0x86);
        }
        M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
        func_800FFBF8(arg0 + 0x70, 0xBFC00000, 0x3E4CCCCD, 0x3F800000);
        func_800B680C(arg0);
    }
    func_8096E6B4(arg0);
    func_8096E7DC(arg0, 0);
}
