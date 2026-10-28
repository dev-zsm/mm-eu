// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137070(u8 *);                      /* extern */
M2C_UNK func_8013E1B4(s32, s32, M2C_UNK *, M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_80A7AC14(u8 *, s32);                 /* extern */
extern M2C_UNK D_8013E404;
extern M2C_UNK D_8013E454;
extern M2C_UNK D_80A7A7B4;
extern M2C_UNK D_80A7CF60;

void func_80001458(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    func_8013E1B4(arg1, arg0 + 0x300, &D_80A7CF60, &D_80A7A7B4, &D_8013E404, &D_8013E454);
    if (M2C_FIELD(arg0, f32 *, 0x8C) > 8.0f) {
        if (M2C_FIELD(arg0, u16 *, 0x374) & 2) {
            temp_f0 = M2C_FIELD(arg0, f32 *, 0x160);
            if ((temp_f0 < M2C_FIELD(arg0, f32 *, 0x164)) && (temp_f0 >= 0.0f)) {
                func_800B8C4C(arg0, 0x2909);
            }
        } else {
            func_800B8D94(arg0, 0x2108);
        }
    }
    if (!(M2C_FIELD(arg0, u16 *, 0x374) & 0x2000)) {
        func_80137070(arg0 + 0x148);
    }
    M2C_FIELD(arg0, u16 *, 0x374) = (u16) (M2C_FIELD(arg0, u16 *, 0x374) & 0xDFFF);
    if (M2C_FIELD(arg0, u8 *, 0x114) != 0) {
        func_80A7AC14(arg0, arg1);
    }
}
