#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_8012AD58(s16, M2C_UNK);                /* extern */
M2C_UNK func_8012ADA0(s16, M2C_UNK);                /* extern */
M2C_UNK func_8012AE28(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s16 func_8012AF4C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_80137788(u8 *, M2C_UNK *, M2C_UNK, f32, f32, s32, f32); /* extern */
extern M2C_UNK D_6009220;
extern M2C_UNK D_8094CA10;

void func_800005D4(u8 *arg0, u8 *arg1) {
    u8 *this = arg0;
    s16 sp32;
    s16 temp_v0;

    if (M2C_FIELD(this, u16 *, 0x90) & 1) {
        M2C_FIELD(this, s32 *, 4) = (s32) (M2C_FIELD(this, s32 *, 4) & ~0x10);
        M2C_FIELD(this, M2C_UNK **, 0x2FC) = &D_8094CA10;
        M2C_FIELD(this, f32 *, 0x64) = 0.0f;
        M2C_FIELD(this, f32 *, 0x6C) = 0.0f;
        func_80137788(this + 0x1DC, &D_6009220, 0x3F800000, 0.0f, 16.0f, 2, 0.0f);
        M2C_FIELD(this, u16 *, 0x2EC) = (u16) (M2C_FIELD(this, u16 *, 0x2EC) | 2);
        temp_v0 = func_8012AF4C(M2C_FIELD(arg1, s32 *, 0x800), 3);
        sp32 = temp_v0;
        func_8012AD58(temp_v0, 0x6978);
        func_8012AE28(sp32, 7, 0, 0, 0);
        func_8012ADA0(sp32, 0x14);
        func_800B8C4C(arg0, 0x180A);
    }
    func_800FFCBC(arg0 + 0xBE, M2C_FIELD(arg0, s16 *, 0x92), 2, 0x7D0, 0x100);
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
}
