#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
extern f32 D_808D303C;
extern f32 D_808D3040;

void func_800003C8(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    if (M2C_FIELD(arg0, u8 *, 0x18C) == 0xA) {
        M2C_FIELD(arg0, u8 *, 0x18C) = 0U;
        M2C_FIELD(arg0, s8 *, 0x368) = 0;
        M2C_FIELD(arg0, f32 *, 0x2C4) = 0.0f;
        func_800BF550(arg1, arg0, arg0 + 0x2D0, 0xB, 2, M2C_FIELD(arg0, f32 *, 0x58) * D_808D303C, M2C_FIELD(arg0, f32 *, 0x58) * 20.0f);
        if (D_808D3040 < M2C_FIELD(arg0, f32 *, 0x58)) {
            M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x400);
            return;
        }
        M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) | 0x200);
    }
}
