// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_800FFCBC(u8 *, s16, M2C_UNK, M2C_UNK, s32); /* extern */
M2C_UNK func_80A5E7E0(u8 *);                      /* extern */
M2C_UNK func_80A5ED50(u8 *);                      /* extern */
extern f32 D_80A6046C;
extern f32 D_80A60470;

void func_800026C4(u8 *arg0, s32 arg1) {
    s16 temp_v0;

    func_800FFCBC(arg0 + 0x32, M2C_FIELD(arg0, s16 *, 0x92), 0xA, 0xFA0, 0x14);
    temp_v0 = M2C_FIELD(arg0, s16 *, 0x2A2);
    if ((temp_v0 == 0xB) || (temp_v0 == 0xA)) {
        if (M2C_FIELD(arg0, s16 *, 0x2A0) != 0) {
            func_800BF550(arg1, arg0, arg0 + 0x2D4, 0xC, 2, D_80A6046C, D_80A60470);
            M2C_FIELD(arg0, s16 *, 0x2A0) = 0;
            M2C_FIELD(arg0, s16 *, 0x2A2) = 0;
            goto block_4;
        }
    } else {
block_4:
        if (M2C_FIELD(arg0, s16 *, 0x290) == 0) {
            M2C_FIELD(arg0, f32 *, 0x1050) = 60.0f;
            M2C_FIELD(arg0, f32 *, 0x104C) = 60.0f;
            if (M2C_FIELD(arg0, s32 *, 0x29C) == 0) {
                func_80A5E7E0(arg0);
                return;
            }
            func_80A5ED50(arg0);
        }
    }
}
