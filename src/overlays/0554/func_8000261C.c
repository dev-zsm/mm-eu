#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6490(u8 *);                      /* extern */
M2C_UNK func_800E0F5C(s32, s32);                    /* extern */
M2C_UNK func_800E10CC(s32, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E731C(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
s32 func_8012F9A8(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80136ED0(s32, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
extern M2C_UNK D_6011AC8;
extern M2C_UNK D_6012DE0;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80BA3238;
extern M2C_UNK D_80BA455C;
extern M2C_UNK D_80BA45C0;
extern M2C_UNK D_80BA45EC;
extern M2C_UNK D_80BA45F8;

void func_8000261C(u8 *arg0, s32 arg1) {
    s32 sp30;
    s32 temp_a1;
    s32 temp_v0;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x41A00000);
    func_80136ED0(arg1, arg0 + 0x148, &D_6011AC8, &D_6012DE0, arg0 + 0x1F8, arg0 + 0x264, 0x12);
    temp_a1 = arg0 + 0x190;
    sp30 = temp_a1;
    func_800E0F5C(arg1, temp_a1);
    func_800E10CC(arg1, temp_a1, arg0, &D_80BA45C0);
    func_800E731C(arg0 + 0xA0, &D_80BA45F8, &D_80BA45EC);
    if (M2C_FIELD(arg0, s32 *, 0x138) != 0) {
        temp_v0 = func_8012F9A8(arg1 + 0x17D88, 0xA1);
        M2C_FIELD(arg0, s32 *, 0x1F4) = temp_v0;
        if (temp_v0 < 0) {
            func_800B6490(arg0);
        }
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_80BA455C;
    M2C_FIELD(arg0, M2C_UNK **, 0x18C) = &D_80BA3238;
}
