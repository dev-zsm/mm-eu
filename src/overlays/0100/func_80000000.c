#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(u8 *, M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B64E0(u8 *, f32);             /* extern */
M2C_UNK func_800E0CD4(s32, u8 *, u8 *, M2C_UNK *, u8 *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
M2C_UNK func_80136E1C(s32, u8 *, M2C_UNK *, M2C_UNK *, u8 *, u8 *, s32); /* extern */
M2C_UNK func_808BECC0(u8 *);                      /* extern */
extern M2C_UNK D_6000444;
extern M2C_UNK D_6001A30;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_808C047C;
extern M2C_UNK D_808C048C;
extern M2C_UNK D_808C04AC;
extern M2C_UNK D_808C04B4;

void func_80000000(u8 *arg0, s32 arg1) {
    s16 temp_t1;
    s32 var_v1;
    u8 *temp_v0;

    func_800FF8DC(arg0, &D_808C04B4);
    func_80136E1C(arg1, arg0 + 0x144, &D_6001A30, &D_6000444, arg0 + 0x188, arg0 + 0x1E8, 0x10);
    func_800E72F0(arg0 + 0xA0, &D_808C048C, &D_808C04AC);
    func_800E0CD4(arg1, arg0 + 0x384, arg0, &D_808C047C, arg0 + 0x3A4);
    func_800B3B14(arg0 + 0xBC, 0x44BB8000, &D_800B3F30, 0x420C0000);
    M2C_FIELD(arg0, s16 *, 0x250) = 0;
    func_808BECC0(arg0);
    func_800B64E0(arg0, 0);
    var_v1 = 0;
    do {
        temp_v0 = M2C_FIELD(arg0, s32 *, 0x3A0) + var_v1;
        var_v1 += 0x40;
        M2C_FIELD(temp_v0, s16 *, 0x36) = (M2C_FIELD(temp_v0, s16 *, 0x2E));
    } while (var_v1 != 0xC0);
}
