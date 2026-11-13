#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B6564(u8 *, f32);                 /* extern */
M2C_UNK func_800BC8F4(u8 *, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80137828(s32, M2C_UNK *, M2C_UNK);     /* extern */
extern M2C_UNK D_6000208;
extern M2C_UNK D_808B2960;
extern f32 D_808B45C4;

void func_80001E40(u8 *arg0, s32 arg1) {
    func_80137828(arg0 + 0x144, &D_6000208, 0xC0A00000);
    M2C_FIELD(arg0, s16 *, 0x18E) = (s16) arg1;
    M2C_FIELD(arg0, u8 *, 0x24D) = (u8) (M2C_FIELD(arg0, u8 *, 0x24D) & 0xFFFE);
    func_800B6564(arg0, M2C_FIELD(arg0, f32 *, 0x1F8) * D_808B45C4);
    if (arg1 == 2) {
        func_800BC8F4(arg0, 0, 0x9B, 0, 0x2A);
    } else if (arg1 == 3) {
        func_800BC8F4(arg0, 0, 0x9B, 0, 0x2A);
        M2C_FIELD(arg0, s8 *, 0x18C) = 0x20;
        M2C_FIELD(arg0, f32 *, 0x200) = 0.75f;
        M2C_FIELD(arg0, f32 *, 0x1FC) = 2.0f;
    } else {
        func_800BC8F4(arg0, 0x4000, 0xFF, 0, 0x2A);
    }
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808B2960;
}
