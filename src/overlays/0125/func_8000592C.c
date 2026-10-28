// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BE288(u8 *, u8 *);              /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
M2C_UNK func_808E62E8(u8 *, M2C_UNK);             /* extern */
extern M2C_UNK D_600276C;
extern M2C_UNK D_808EA078;

void func_8000592C(u8 *arg0, s32 arg1) {
    s32 temp_v0;

    func_80137828(arg0 + 0x144, &D_600276C, 0xC0400000);
    M2C_FIELD(arg0, u8 *, 0x63D) = (u8) (M2C_FIELD(arg0, u8 *, 0x63D) & 0xFFFE);
    M2C_FIELD(arg0, s16 *, 0x2BA) = 0x14;
    M2C_FIELD(arg0, f32 *, 0x70) = 10.0f;
    M2C_FIELD(arg0, f32 *, 0x74) = -2.0f;
    M2C_FIELD(arg0, f32 *, 0x68) = 0.0f;
    if (arg1 != 0) {
        func_800BE288(arg0, arg0 + 0x62C);
    }
    func_808E62E8(arg0, 0x38D3);
    temp_v0 = M2C_FIELD(arg0, s32 *, 4);
    if ((temp_v0 & 0x2000) == 0x2000) {
        M2C_FIELD(arg0, s32 *, 4) = (s32) (temp_v0 & ~0x2000);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808EA078;
}
