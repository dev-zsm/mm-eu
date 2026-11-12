#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B3B14(s32, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800B6564(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800E1134(u8 *, s32, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_80136ED0(u8 *, s32, M2C_UNK *, M2C_UNK *, s32, s32, s32); /* extern */
M2C_UNK func_801378E0(s32, M2C_UNK *);              /* extern */
M2C_UNK func_80937740(u8 *, u8 *);              /* extern */
extern M2C_UNK D_60005C0;
extern M2C_UNK D_6006260;
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_80937F4C;
extern M2C_UNK D_80938400;

void func_80000078(u8 *arg0, u8 *arg1) {
    s32 sp34;
    s32 temp_a1;

    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x42100000);
    temp_a1 = arg0 + 0x190;
    sp34 = temp_a1;
    func_80136ED0(arg1, temp_a1, &D_6006260, &D_60005C0, arg0 + 0x1D4, arg0 + 0x234, 0x10);
    func_801378E0(sp34, &D_60005C0);
    func_800E1134(arg1, arg0 + 0x144, arg0, &D_80938400);
    M2C_FIELD(arg0, u8 *, 0xB6) = 0xFF;
    func_800B6564(arg0, 0x3C23D70A);
    M2C_FIELD(arg0, M2C_UNK **, 0x394) = &D_80937F4C;
    if (M2C_FIELD(arg1, u8 *, 0x18B48) == 1) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x10000);
    }
    M2C_FIELD(arg0, s16 *, 0x2A0) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F) = 6;
    func_80937740(arg0, arg1);
}
