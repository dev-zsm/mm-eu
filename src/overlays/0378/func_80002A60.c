// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_80A8679C();                            /* extern */
extern M2C_UNK D_80A86840;
extern f32 D_80A8945C;

void func_80002A60(u8 *arg0, u8 *arg1) {
    if (M2C_FIELD(arg1, u8 *, 0x1F2C) == 0) {
        func_80A8679C();
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 1);
        if (M2C_FIELD(arg0, s16 *, 0x2E0) == 0x21) {
            M2C_FIELD(arg0, f32 *, 0x54) = (f32) D_80A8945C;
        } else {
            M2C_FIELD(arg0, f32 *, 0x54) = 200.0f;
        }
        if ((M2C_FIELD(arg0, u8 *, 0x2A5) & 2) && (M2C_FIELD(arg0, u8 *, 0xB9) == 0xF)) {
            M2C_FIELD(arg0, s8 *, 0x335) = 1;
            M2C_FIELD(arg0, M2C_UNK **, 0x290) = &D_80A86840;
        }
    }
}
