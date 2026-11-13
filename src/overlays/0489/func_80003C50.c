#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0489.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80B28B04(u8 *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_80B29014(u8 *);                      /* extern */
M2C_UNK func_80B294F0(u8 *, s32);                 /* extern */
M2C_UNK func_80B2C43C(u8 *);                      /* extern */
extern f32 D_80B33BC0;

void func_80003C50(u8 *arg0, s32 arg1) {
    s16 temp_v0;
    s16 temp_v0_2;

    func_80B29014(arg0);
    func_80B294F0(arg0, arg1);
    func_80B28B04(arg0, 0x320, 0);
    func_800B8D94(arg0, 0x320A);
    if (D_80B33BC0 <= M2C_FIELD(arg0, f32 *, 0x320)) {
        M2C_FIELD(arg0, s8 *, 0x38A) = 1;
    }
    temp_v0 = M2C_FIELD(arg0, u8 *, 0x389);
    if ((s32) temp_v0 >= 0xF9) {
        M2C_FIELD(arg0, u8 *, 0x389) = 0xFFU;
    } else {
        M2C_FIELD(arg0, u8 *, 0x389) = (u8) (temp_v0 + 6);
    }
    if ((s32) M2C_FIELD(arg0, u8 *, 0x389) >= 0x81) {
        M2C_FIELD(arg0, u8 *, 0x2B0) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B0) | 1);
        M2C_FIELD(arg0, u8 *, 0x2B1) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B1) | 1);
        M2C_FIELD(arg0, u8 *, 0x2B2) = (u8) (M2C_FIELD(arg0, u8 *, 0x2B2) | 1);
    }
    if (M2C_FIELD(arg0, u8 *, 0x389) == 0xFF) {
        temp_v0_2 = M2C_FIELD(arg0, u8 *, 0x38D);
        if ((s32) temp_v0_2 >= 0xF5) {
            M2C_FIELD(arg0, u8 *, 0x38D) = 0xFFU;
            func_80B2C43C(arg0);
            return;
        }
        M2C_FIELD(arg0, u8 *, 0x38D) = (u8) (temp_v0_2 + 0xA);
    }
}
