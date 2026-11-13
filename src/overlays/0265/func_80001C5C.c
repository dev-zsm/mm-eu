#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0265.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_809944AC(u8 *);                      /* extern */
extern f32 D_80995E80;
extern f32 D_80995E84;

void func_80001C5C(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    if (M2C_FIELD(arg0, s16 *, 0x2AA) == 0xB) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x2A8);
        if ((temp_v0 != 0) && (temp_v0 < 0x3C)) {
            M2C_FIELD(arg0, s16 *, 0x2AA) = 0xA;
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 0x288) == 0) && (M2C_FIELD(arg0, s16 *, 0x2A8) == 0)) {
        if ((M2C_FIELD(arg0, s16 *, 0x2AA) == 0xB) || (M2C_FIELD(arg0, s16 *, 0x2AA) == 0xA)) {
            func_800BF550(arg1, arg0, arg0 + 0x2B4, 0xC, 2, D_80995E80, D_80995E84);
            M2C_FIELD(arg0, s16 *, 0x2A8) = 0;
            M2C_FIELD(arg0, s16 *, 0x2AA) = 0;
        }
        func_809944AC(arg0);
    }
}
