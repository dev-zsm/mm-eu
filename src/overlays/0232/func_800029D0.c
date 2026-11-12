#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0232.h"

M2C_UNK func_800B680C(u8 *);                      /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8096E81C(u8 *, u8 *);              /* extern */
M2C_UNK func_8096EB58(u8 *, u8 *);              /* extern */
extern M2C_UNK D_8096F1A8;

void func_800029D0(u8 *arg0, u8 *arg1) {
    u8 *temp_v1;
    s16 temp_v0_2;
    s16 var_v1;
    u32 temp_v0;

    temp_v1 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(arg0, u16 *, 0x90) & 1) {
        temp_v0 = M2C_FIELD(arg0, u16 *, 0x280);
        if (temp_v0 & 0x10) {
            M2C_FIELD(arg0, u16 *, 0x280) = (u16) (temp_v0 & 0xFFEF);
            func_800B8C4C(arg0, 0x28EF);
        }
        M2C_FIELD(arg0, f32 *, 0x70) = 0.0f;
        M2C_FIELD(arg0, f32 *, 0x74) = -3.0f;
        if (M2C_FIELD(temp_v1, u8 *, 0x14B) == 4) {
            func_8096EB58(arg0, arg1);
        }
    }
    temp_v0_2 = M2C_FIELD(arg0, s16 *, 0x28A);
    if (temp_v0_2 == 0) {
        var_v1 = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x28A) = (s16) (temp_v0_2 - 1);
        var_v1 = M2C_FIELD(arg0, s16 *, 0x28A);
    }
    if (var_v1 == 0) {
        M2C_FIELD(arg0, s16 *, 0x290) = 0;
        func_8096E81C(arg0, arg1);
        M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_8096F1A8;
    }
    func_800B680C(arg0);
}
