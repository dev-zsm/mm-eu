#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0365.h"

M2C_UNK func_800BF550(s32, u8 *, u8 *, M2C_UNK, s32, f32, f32); /* extern */
M2C_UNK func_80A5E4E4(u8 *);                      /* extern */
extern f32 D_80A6045C;
extern f32 D_80A60460;

void func_80002240(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    if (M2C_FIELD(arg0, s16 *, 0x2A2) == 0xB) {
        temp_v0 = M2C_FIELD(arg0, s16 *, 0x2A0);
        if ((temp_v0 != 0) && (temp_v0 < 0x3C)) {
            M2C_FIELD(arg0, s16 *, 0x2A2) = 0xA;
        }
    }
    if ((M2C_FIELD(arg0, s16 *, 0x290) == 0) && (M2C_FIELD(arg0, s16 *, 0x2A0) == 0)) {
        if ((M2C_FIELD(arg0, s16 *, 0x2A2) == 0xB) || (M2C_FIELD(arg0, s16 *, 0x2A2) == 0xA)) {
            func_800BF550(arg1, arg0, arg0 + 0x2D4, 0xC, 2, D_80A6045C, D_80A60460);
            M2C_FIELD(arg0, s16 *, 0x2A0) = 0;
            M2C_FIELD(arg0, s16 *, 0x2A2) = 0;
        }
        func_80A5E4E4(arg0);
    }
}
