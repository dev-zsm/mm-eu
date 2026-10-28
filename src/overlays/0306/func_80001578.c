// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800FEC70(u8 *, s16, M2C_UNK, u8 *); /* extern */
s32 func_80137070(u8 *);                          /* extern */
M2C_UNK func_80A0D120(u8 *);                      /* extern */
M2C_UNK func_80A0D214(u8 *);                      /* extern */
extern f32 D_80A0E4F0;
extern f32 D_80A0E4F4;
extern f32 D_80A0E4F8;
extern f32 D_80A0E4FC;

void func_80001578(u8 *arg0, M2C_UNK arg1) {
    f32 temp_f0;
    f32 temp_f2;
    s16 temp_v0;

    func_800FEC70(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 0x600, arg0);
    if (func_80137070(arg0 + 0x144) != 0) {
        temp_v0 = M2C_FIELD(M2C_FIELD(arg0, u8 **, 0x120), s16 *, 0x1C);
        if ((temp_v0 == 7) || (temp_v0 == 8)) {
            func_80A0D120(arg0);
            return;
        }
        func_80A0D214(arg0);
        return;
    }
    temp_f2 = M2C_FIELD(arg0, f32 *, 0x15C);
    if (temp_f2 > 7.0f) {
        temp_f0 = 1.5f - ((temp_f2 - 7.0f) * D_80A0E4F0);
        M2C_FIELD(arg0, f32 *, 0x2A8) = temp_f0;
        M2C_FIELD(arg0, f32 *, 0x2A4) = temp_f0;
        return;
    }
    M2C_FIELD(arg0, f32 *, 0x2A8) = (f32) ((D_80A0E4F4 * temp_f2) + D_80A0E4F8);
    M2C_FIELD(arg0, f32 *, 0x2A4) = (f32) ((D_80A0E4FC * temp_f2) + 1.0f);
}
