#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800BBED8(s32, s32, u8 *, M2C_UNK);   /* extern */
M2C_UNK func_800E0F5C(s32, u8 *);                 /* extern */
M2C_UNK func_800E10CC(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800FF8DC(u8 *, M2C_UNK *);           /* extern */
s8 func_8012F9A8(s32, M2C_UNK);                     /* extern */
extern M2C_UNK D_800B3F30;
extern u8 D_801E7DFE;
extern M2C_UNK D_80B310D0;
extern M2C_UNK D_80B3360C;
extern M2C_UNK D_80B339C8;
extern u8 *D_80B35128;

void func_800030D0(u8 *arg0, s32 arg1) {
    u8 *temp_a1;

    func_800FF8DC(arg0, &D_80B339C8);
    M2C_FIELD(arg0, M2C_UNK **, 0x138) = &D_80B310D0;
    func_800BBED8(arg1, arg1 + 0x1CA0, arg0, 4);
    temp_a1 = arg0 + 0x2A0;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_80B3360C);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFE;
    func_800B3B14(arg0 + 0xBC, 0.0f, &D_800B3F30, 0x41900000);
    M2C_FIELD(arg0, s8 *, 0x2F4) = func_8012F9A8(arg1 + 0x17D88, 0xA7);
    if (M2C_FIELD(arg0, s8 *, 0x2F4) < 0) {
        func_800B6490(arg0);
    }
    if (!(D_801E7DFE & 1)) {
        func_800B6490(arg0);
    }
    D_80B35128 = arg0;
}
